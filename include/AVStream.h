#pragma once
#include <global.h>

namespace FFmpeg
{
	class Format;

	class AVStream : public Wrapper<::AVStream>
	{
		// 生命周期
	public:
		AVStream(::AVStream *stream, Format *format);

		// 公共方法
	public:
		void CopyParamTo(shared_ptr<FFmpeg::AVStream> dstStream);

		// 属性访问器
	public:
		::AVMediaType get_MediaType(void);
		int get_Index(void);
		int get_DstIndex(void);
		void set_DstIndex(int dstIndex);
		int64_t get_StartDts(void);
		void set_StartDts(int64_t value);
		int64_t get_StartPts(void);
		void set_StartPts(int64_t value);
		FFmpeg::Format *const get_AffFormat(void);

		// 私有字段
	private:
		FFmpeg::Format *_affFormat = nullptr;
		int _dstIndex = -1;
		int64_t _startDts = -1;
		int64_t _startPts = -1;
	};

}