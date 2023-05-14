#pragma once
#include <global.h>

namespace FFmpeg
{
	class AVCodec : Wrapper<::AVCodec>
	{
	public:
		AVCodec(wchar_t *codecName);
	};
}
