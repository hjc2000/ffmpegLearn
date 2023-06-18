#include "FFmpegEnum.h"

std::string &operator<<(std::string &str, FFmpeg::AVMediaType const type)
{
	str = std::string{::av_get_media_type_string(type)};
	return str;
}

void operator>>(std::string const &str, FFmpeg::AVMediaType &type)
{
	using FFmpeg::AVMediaType;
	/*
	enum AVMediaType {
	AVMEDIA_TYPE_UNKNOWN = -1,  ///< Usually treated as AVMEDIA_TYPE_DATA
	AVMEDIA_TYPE_VIDEO,
	AVMEDIA_TYPE_AUDIO,
	AVMEDIA_TYPE_DATA,          ///< Opaque data information usually continuous
	AVMEDIA_TYPE_SUBTITLE,
	AVMEDIA_TYPE_ATTACHMENT,    ///< Opaque data information usually sparse
	AVMEDIA_TYPE_NB
};
	*/

	if (str == "audio")
		type = AVMediaType::AVMEDIA_TYPE_AUDIO;
	else if (str == "video")
		type = AVMediaType::AVMEDIA_TYPE_VIDEO;
	else if (str == "data")
		type = AVMediaType::AVMEDIA_TYPE_DATA;
	else if (str == "subtitle")
		type = AVMediaType::AVMEDIA_TYPE_SUBTITLE;
	else if (str == "nb")
		type = AVMediaType::AVMEDIA_TYPE_NB;
	else
		type = AVMediaType::AVMEDIA_TYPE_UNKNOWN;
}
