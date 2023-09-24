#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL3/SDL.h>

auto handleError(auto errCode) {
    std::cout << SDL_GetError() << std::endl;
    return errCode;
}

constexpr int WIN_WIDTH = 800, WIN_HEIGHT = 600;

constexpr auto SHAPE_SIZE = 16.0f;
constexpr auto SHAPE_START_X = (float)WIN_WIDTH / 2 - SHAPE_SIZE / 2,
               SHAPE_START_Y = (float)WIN_HEIGHT / 2 - SHAPE_SIZE / 2;

constexpr auto SPEED = 2.0f;

int main() {
    handleError(SDL_Init(SDL_INIT_EVERYTHING));
    auto window = handleError(SDL_CreateWindow("SDL3 Template Project", WIN_WIDTH, WIN_HEIGHT, 0));
    auto renderer = handleError(SDL_CreateRenderer(window, NULL, 0));

    auto x = SHAPE_START_X, y = SHAPE_START_Y;

    SDL_Event event;
    bool running = true;
    while (running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_FRect rect{ x, y, SHAPE_SIZE, SHAPE_SIZE };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &rect);

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

        SDL_RenderPresent(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
