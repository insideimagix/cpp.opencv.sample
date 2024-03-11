#pragma once
#include "../../CommonType.h"

class ImageService
{
public:
	ImageService();
	virtual ~ImageService();

	bool			OpenImageFile(const string& _fileName, const ecOpenFlag _openFlag);
	bool			GetImageBuffer(Mat& _cvImage) const;
	bool			GetImageBuffer(stBufferInfo& _info) const;
	bool			GetImageBuffer(uint8_t* _pBuffer) const;

private:
	int				ConvertOpenFlag(const ecOpenFlag _openFlag) const;

	Mat				m_cvImage;
};

