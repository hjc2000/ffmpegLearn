#include "FFmpegEnum.h"

std::string &operator<<(std::string &str, FFmpeg::AVMediaType type)
{
	str = std::string{::av_get_media_type_string(type)};
	return str;
}