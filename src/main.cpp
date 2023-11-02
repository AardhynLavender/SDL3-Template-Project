#define SDL_MAIN_HANDLED

#include <iostream>
#include <renderer.h>

constexpr int WIN_WIDTH = 100, WIN_HEIGHT = 100;

constexpr auto SHAPE_SIZE = 16;
constexpr int SHAPE_START_X = (float) WIN_WIDTH / 2 - SHAPE_SIZE / 2,
        SHAPE_START_Y = (float) WIN_HEIGHT / 2 - SHAPE_SIZE / 2;

constexpr auto SPEED = 2.0f;

int main() {
    handleSDLError(SDL_Init(SDL_INIT_EVERYTHING));

    Window window{"SDL3 Template Project", Window::centered, {WIN_WIDTH, WIN_HEIGHT}, {.opengl = true,}};
    Renderer renderer{window, {.accelerated = true, .vsync = true,}};

    auto x = SHAPE_START_X, y = SHAPE_START_Y;

    SDL_Event event;
    bool running = true;

    while (running) {
        renderer.Clear();
        renderer.DrawRect({{x,          y},
                           {SHAPE_SIZE, SHAPE_SIZE}}, Colors::white, Colors::transparent);

        while (SDL_PollEvent(&event))
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    switch (event.key.keysym.sym) {
                        case SDL_KeyCode::SDLK_RIGHT:
                        case SDL_KeyCode::SDLK_a:
                            x += -SPEED;
                            break;
                        case SDL_KeyCode::SDLK_LEFT:
                        case SDL_KeyCode::SDLK_d:
                            x += SPEED;
                            break;
                        case SDL_KeyCode::SDLK_UP:
                        case SDL_KeyCode::SDLK_w:
                            y += -SPEED;
                            break;
                        case SDL_KeyCode::SDLK_DOWN:
                        case SDL_KeyCode::SDLK_s:
                            y += SPEED;
                            break;
                    }
                    break;
            }

        renderer.Present();
    }

    return EXIT_SUCCESS;
}
