/*
	Let's see where we go with this
*/

#ifndef WTDMS_EXCEPT_H_
#define WTDMS_EXCEPT_H_

#include <exception>

namespace wtdms
{

class dimension_range : public std::logic_error
{
	public:
		dimension_range() : std::logic_error("Dimension doesn't exist; index out of range") {}
};

}

#endif //WTDMS_H_