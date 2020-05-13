#include "Images.h"

Images::Images(std::string _repertory)
	:	repertory(_repertory)
{

}

const Image& Images::operator[](const int& index) const
{
	return images[index];
}