/// @ref gtc_random
/// @file glm/gtc/random.inl

#include "../geometric.hpp"
#include "../exponential.hpp"
#include "../trigonometric.hpp"
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

namespace glm{
namespace detail
{
	template <length_t L, typename T, precision P>
	struct compute_rand
	{
		GLM_FUNC_QUALIFIER static vec<L, T, P> call();
	};

	template <precision P>
	struct compute_rand<1, uint8, P>
	{
		GLM_FUNC_QUALIFIER static vec<1, uint8, P> call()
		{
			return vec<1, uint8, P>(
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template <precision P>
	struct compute_rand<2, uint8, P>
	{
		GLM_FUNC_QUALIFIER static vec<2, uint8, P> call()
		{
			return vec<2, uint8, P>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template <precision P>
	struct compute_rand<3, uint8, P>
	{
		GLM_FUNC_QUALIFIER static vec<3, uint8, P> call()
		{
			return vec<3, uint8, P>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template <precision P>
	struct compute_rand<4, uint8, P>
	{
		GLM_FUNC_QUALIFIER static vec<4, uint8, P> call()
		{
			return vec<4, uint8, P>(
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max(),
				std::rand() % std::numeric_limits<uint8>::max());
		}
	};

	template <length_t L, precision P>
	struct compute_rand<L, uint16, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint16, P> call()
		{
			return
				(vec<L, uint16, P>(compute_rand<L, uint8, P>::call()) << static_cast<uint16>(8)) |
				(vec<L, uint16, P>(compute_rand<L, uint8, P>::call()) << static_cast<uint16>(0));
		}
	};

	template <length_t L, precision P>
	struct compute_rand<L, uint32, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint32, P> call()
		{
			return
				(vec<L, uint32, P>(compute_rand<L, uint16, P>::call()) << static_cast<uint32>(16)) |
				(vec<L, uint32, P>(compute_rand<L, uint16, P>::call()) << static_cast<uint32>(0));
		}
	};

	template <length_t L, precision P>
	struct compute_rand<L, uint64, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint64, P> call()
		{
			return
				(vec<L, uint64, P>(compute_rand<L, uint32, P>::call()) << static_cast<uint64>(32)) |
				(vec<L, uint64, P>(compute_rand<L, uint32, P>::call()) << static_cast<uint64>(0));
		}
	};

	template <length_t L, typename T, precision P>
	struct compute_linearRand
	{
		GLM_FUNC_QUALIFIER static vec<L, T, P> call(vec<L, T, P> const& Min, vec<L, T, P> const& Max);
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, int8, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, int8, P> call(vec<L, int8, P> const& Min, vec<L, int8, P> const& Max)
		{
			return (vec<L, int8, P>(compute_rand<L, uint8, P>::call() % vec<L, uint8, P>(Max + static_cast<int8>(1) - Min))) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, uint8, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint8, P> call(vec<L, uint8, P> const& Min, vec<L, uint8, P> const& Max)
		{
			return (compute_rand<L, uint8, P>::call() % (Max + static_cast<uint8>(1) - Min)) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, int16, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, int16, P> call(vec<L, int16, P> const& Min, vec<L, int16, P> const& Max)
		{
			return (vec<L, int16, P>(compute_rand<L, uint16, P>::call() % vec<L, uint16, P>(Max + static_cast<int16>(1) - Min))) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, uint16, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint16, P> call(vec<L, uint16, P> const& Min, vec<L, uint16, P> const& Max)
		{
			return (compute_rand<L, uint16, P>::call() % (Max + static_cast<uint16>(1) - Min)) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, int32, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, int32, P> call(vec<L, int32, P> const & Min, vec<L, int32, P> const& Max)
		{
			return (vec<L, int32, P>(compute_rand<L, uint32, P>::call() % vec<L, uint32, P>(Max + static_cast<int32>(1) - Min))) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, uint32, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint32, P> call(vec<L, uint32, P> const& Min, vec<L, uint32, P> const& Max)
		{
			return (compute_rand<L, uint32, P>::call() % (Max + static_cast<uint32>(1) - Min)) + Min;
		}
	};
 
	template<length_t L, precision P>
	struct compute_linearRand<L, int64, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, int64, P> call(vec<L, int64, P> const& Min, vec<L, int64, P> const& Max)
		{
			return (vec<L, int64, P>(compute_rand<L, uint64, P>::call() % vec<L, uint64, P>(Max + static_cast<int64>(1) - Min))) + Min;
		}
	};

	template<length_t L, precision P>
	struct compute_linearRand<L, uint64, P>
	{
		GLM_FUNC_QUALIFIER static vec<L, uint64, P> call(vec<L, uint64, P> const& Min, vec<L, uint64, P> const& Max)
		{
			return (compute_rand<L, uint64, P>::call() % (Max + static_cast<uint64>(1) - Min)) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, float, lowp>
	{
		GLM_FUNC_QUALIFIER static vec<L, float, lowp> call(vec<L, float, lowp> const& Min, vec<L, float, lowp> const& Max)
		{
			return vec<L, float, lowp>(compute_rand<L, uint8, lowp>::call()) / static_cast<float>(std::numeric_limits<uint8>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, float, mediump>
	{
		GLM_FUNC_QUALIFIER static vec<L, float, mediump> call(vec<L, float, mediump> const& Min, vec<L, float, mediump> const& Max)
		{
			return vec<L, float, mediump>(compute_rand<L, uint16, mediump>::call()) / static_cast<float>(std::numeric_limits<uint16>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, float, highp>
	{
		GLM_FUNC_QUALIFIER static vec<L, float, highp> call(vec<L, float, highp> const& Min, vec<L, float, highp> const& Max)
		{
			return vec<L, float, highp>(compute_rand<L, uint32, highp>::call()) / static_cast<float>(std::numeric_limits<uint32>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, double, lowp>
	{
		GLM_FUNC_QUALIFIER static vec<L, double, lowp> call(vec<L, double, lowp> const& Min, vec<L, double, lowp> const& Max)
		{
			return vec<L, double, lowp>(compute_rand<L, uint16, lowp>::call()) / static_cast<double>(std::numeric_limits<uint16>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, double, mediump>
	{
		GLM_FUNC_QUALIFIER static vec<L, double, mediump> call(vec<L, double, mediump> const& Min, vec<L, double, mediump> const& Max)
		{
			return vec<L, double, mediump>(compute_rand<L, uint32, mediump>::call()) / static_cast<double>(std::numeric_limits<uint32>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, double, highp>
	{
		GLM_FUNC_QUALIFIER static vec<L, double, highp> call(vec<L, double, highp> const& Min, vec<L, double, highp> const& Max)
		{
			return vec<L, double, highp>(compute_rand<L, uint64, highp>::call()) / static_cast<double>(std::numeric_limits<uint64>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, long double, lowp>
	{
		GLM_FUNC_QUALIFIER static vec<L, long double, lowp> call(vec<L, long double, lowp> const& Min, vec<L, long double, lowp> const& Max)
		{
			return vec<L, long double, lowp>(compute_rand<L, uint32, lowp>::call()) / static_cast<long double>(std::numeric_limits<uint32>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, long double, mediump>
	{
		GLM_FUNC_QUALIFIER static vec<L, long double, mediump> call(vec<L, long double, mediump> const& Min, vec<L, long double, mediump> const& Max)
		{
			return vec<L, long double, mediump>(compute_rand<L, uint64, mediump>::call()) / static_cast<long double>(std::numeric_limits<uint64>::max()) * (Max - Min) + Min;
		}
	};

	template<length_t L>
	struct compute_linearRand<L, long double, highp>
	{
		GLM_FUNC_QUALIFIER static vec<L, long double, highp> call(vec<L, long double, highp> const& Min, vec<L, long double, highp> const& Max)
		{
			return vec<L, long double, highp>(compute_rand<L, uint64, highp>::call()) / static_cast<long double>(std::numeric_limits<uint64>::max()) * (Max - Min) + Min;
		}
	};
}//namespace detail

	template<typename genType>
	GLM_FUNC_QUALIFIER genType linearRand(genType Min, genType Max)
	{
		return detail::compute_linearRand<1, genType, highp>::call(
			vec<1, genType, highp>(Min),
			vec<1, genType, highp>(Max)).x;
	}

	template<length_t L, typename T, precision P>
	GLM_FUNC_QUALIFIER vec<L, T, P> linearRand(vec<L, T, P> const & Min, vec<L, T, P> const& Max)
	{
		return detail::compute_linearRand<L, T, P>::call(Min, Max);
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType gaussRand(genType Mean, genType Deviation)
	{
		genType w, x1, x2;

		do
		{
			x1 = linearRand(genType(-1), genType(1));
			x2 = linearRand(genType(-1), genType(1));
		
			w = x1 * x1 + x2 * x2;
		} while(w > genType(1));

		return x2 * Deviation * Deviation * sqrt((genType(-2) * log(w)) / w) + Mean;
	}

	template<length_t L, typename T, precision P>
	GLM_FUNC_QUALIFIER vec<L, T, P> gaussRand(vec<L, T, P> const& Mean, vec<L, T, P> const& Deviation)
	{
		return detail::functor2<L, T, P>::call(gaussRand, Mean, Deviation);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T, defaultp> diskRand(T Radius)
	{		
		vec<2, T, defaultp> Result(T(0));
		T LenRadius(T(0));

		do
		{
			Result = linearRand(
				vec<2, T, defaultp>(-Radius),
				vec<2, T, defaultp>(Radius));
			LenRadius = length(Result);
		}
		while(LenRadius > Radius);

		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T, defaultp> ballRand(T Radius)
	{
		vec<3, T, defaultp> Result(T(0));
		T LenRadius(T(0));
		
		do
		{
			Result = linearRand(
				vec<3, T, defaultp>(-Radius),
				vec<3, T, defaultp>(Radius));
			LenRadius = length(Result);
		}
		while(LenRadius > Radius);
		
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<2, T, defaultp> circularRand(T Radius)
	{
		T a = linearRand(T(0), static_cast<T>(6.283185307179586476925286766559));
		return vec<2, T, defaultp>(glm::cos(a), glm::sin(a)) * Radius;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER vec<3, T, defaultp> sphericalRand(T Radius)
	{
		T z = linearRand(T(-1), T(1));
		T a = linearRand(T(0), T(6.283185307179586476925286766559f));

		T r = sqrt(T(1) - z * z);

		T x = r * std::cos(a);
		T y = r * std::sin(a);

		return vec<3, T, defaultp>(x, y, z) * Radius;
	}
}//namespace glm
