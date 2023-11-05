//
// Created by Aardhyn on 5/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_OUTPUT_H
#define SDL3_TEMPLATE_PROJECT_OUTPUT_H

#include <iostream>

namespace Out {
	 constexpr char NL = '\n';
	 constexpr char SPACE = ' ';

	 constexpr bool DEBUG = true;

	 template<typename T>
	 inline void line(T t) {
		 if constexpr (DEBUG)
			 std::cout << t << NL;
	 }

	 template<typename T, typename... TArgs>
	 inline void line(T t, TArgs... args) {
		 if constexpr (DEBUG) {
			 std::cout << t << SPACE;
			 printl(args...);
		 }
	 }

	 template<typename T>
	 inline void lines(T t) {
		 if constexpr (DEBUG)
			 std::cout << t << NL;
	 }

	 template<typename T, typename... TArgs>
	 inline void lines(T t, TArgs... args) {
		 if constexpr (DEBUG) {
			 std::cout << t << NL;
			 lines(args...);
		 }
	 }
}

namespace Err {
	 template<typename T>
	 inline void line(T t) {
		 std::cerr << t << Out::NL;
	 }

	 template<typename T, typename... TArgs>
	 inline void line(T t, TArgs... args) {
		 std::cerr << t << Out::SPACE;
		 line(args...);
	 }

	 template<typename T>
	 inline void lines(T t) {
		 std::cerr << t << Out::NL;
	 }

	 template<typename T, typename... TArgs>
	 inline void lines(T t, TArgs... args) {
		 std::cerr << t << Out::NL;
		 lines(args...);
	 }
}

#endif //SDL3_TEMPLATE_PROJECT_OUTPUT_H
