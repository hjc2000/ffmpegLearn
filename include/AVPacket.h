#pragma once
#include <Wraper.h>
#include <AVUtil.h>
extern "C"
{
#define __STDC_CONSTANT_MACROS
#include <libavformat/avio.h>
#include <libavformat/avformat.h>
}

namespace FFmpeg
{
	class AVPacket : public Wraper<::AVPacket>
	{
	public:
		AVPacket()
		{
			m_pWrapedObj = av_packet_alloc();
		}
		AVPacket(::AVPacket *pAVPacket)
		{
			m_pWrapedObj = av_packet_alloc();
			av_packet_ref(m_pWrapedObj, pAVPacket);
		}
		AVPacket(::AVPacket &ref_AVPacket)
		{
			m_pWrapedObj = av_packet_alloc();
			av_packet_ref(m_pWrapedObj, &ref_AVPacket);
		}
		~AVPacket()
		{
			av_packet_unref(m_pWrapedObj);
		}
	};
}