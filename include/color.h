//
// Created by Aardhyn Lavender on 1/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_COLOR_H
#define SDL3_TEMPLATE_PROJECT_COLOR_H

struct Color {
	 static constexpr unsigned int OPAQUE = 255;
	 static constexpr unsigned int TRANSPARENT = 0;

	 unsigned int red = 0, green = 0, blue = 0, alpha = OPAQUE;
};

namespace Colors {
	 constexpr Color white{ 255, 255, 255, 255 };
	 constexpr Color black{ 0, 0, 0, 255 };
	 constexpr Color transparent{ 0, 0, 0, 0 };

	 constexpr Color red{ 255, 0, 0, 255 };
	 constexpr Color green{ 0, 255, 0, 255 };
	 constexpr Color blue{ 0, 0, 255, 255 };
	 constexpr Color yellow{ 255, 255, 0, 255 };
	 constexpr Color cyan{ 0, 255, 255, 255 };
	 constexpr Color magenta{ 255, 0, 255, 255 };
}

#endif //SDL3_TEMPLATE_PROJECT_COLOR_H
