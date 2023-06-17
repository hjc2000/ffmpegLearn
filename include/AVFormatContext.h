#pragma once

#include <Wraper.h>
extern "C"
{
#define __STDC_CONSTANT_MACROS
#include <libavformat/avio.h>
#include <libavformat/avformat.h>
}

namespace FFmpeg
{
	class AVFormatContext : public Wraper<::AVFormatContext>
	{
	public:
		AVFormatContext()
		{
			m_pWrapedObj = avformat_alloc_context();
		}
		~AVFormatContext()
		{
			avformat_free_context(m_pWrapedObj);
		}
	};
}