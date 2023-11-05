//
// Created by Aardhyn on 5/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_CLOCK_H
#define SDL3_TEMPLATE_PROJECT_CLOCK_H

#include <chrono>
#include <concept.h>

namespace Clock {
	 constexpr auto SECOND_MS = 1000.0f;

	 template<Numeric T = float>
	 class Timer {
	 private:
		  typedef std::chrono::steady_clock ClockType;
		  typedef std::chrono::time_point<ClockType> TimePoint;

		  TimePoint start = ClockType::now();
		  TimePoint end = start;
	 public:
		  inline T elapsed() const { return std::chrono::duration<T>(end - start).count(); }

		  inline T restart() {
			  end = std::chrono::steady_clock::now();
			  auto delta = elapsed();
			  start = end;
			  return delta;
		  }
	 };
}

#endif //SDL3_TEMPLATE_PROJECT_CLOCK_H
