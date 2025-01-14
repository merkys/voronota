#ifndef AUXILIARIES_TIME_UTILITIES_H_
#define AUXILIARIES_TIME_UTILITIES_H_

#include <ctime>

namespace voronota
{

namespace auxiliaries
{

class ElapsedProcessorTime
{
public:
	ElapsedProcessorTime()
	{
		reset();
	}

	void reset()
	{
		start_=std::clock();
	}

	double elapsed_miliseconds() const
	{
		const std::clock_t end=std::clock();
		return (1000.0*static_cast<double>(end-start_)/static_cast<double>(CLOCKS_PER_SEC));
	}

private:
	std::clock_t start_;
};

}

}

#endif /* AUXILIARIES_TIME_UTILITIES_H_ */
