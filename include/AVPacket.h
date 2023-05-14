#pragma once
#include <global.h>
using namespace std;

namespace FFmpeg
{
	class AVStream;
	class Format;

	class AVPacket : public Wrapper<::AVPacket>
	{
	public:
		AVPacket(Format *affFormat);
		~AVPacket();
		void RescaleTsFor(shared_ptr<FFmpeg::AVStream> dstStream);
		void UnRef(void);

		// 访问器
	public:
		int get_AffStreamIndex();
		int64_t get_Pts(void);
		void set_Pts(int64_t pts);
		int64_t get_Dts(void);
		void set_Dts(int64_t dts);
		void set_AffStreamIndex(int index);
		void AdjustStartPtsAndDts(void);

	private:
		::AVPacket _pkt;
		Format *_affFormat = nullptr;

		// 私有方法
	private:
	};

}
