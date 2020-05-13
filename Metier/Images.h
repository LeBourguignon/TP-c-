#pragma once
#include "Image.h"
#include <vector>

class Images
{
private:
	std::vector<Image> images;
	std::string repertory;

public:
	Images(std::string _repertory);

	const Image& operator[](const int& index) const;
};