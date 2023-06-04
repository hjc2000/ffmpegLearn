#include <AVDictionary.h>
#include <iostream>
#include <fstream>
#include <string>
extern "C"
{
#include <libavutil/parseutils.h>
}

using std::cout;
using std::endl;
using std::fstream;
using std::ios_base;
using std::string;

void test_dic()
{
	FFmpeg::AVDictionary dic;
	dic.av_dict_set("name", "hjc");
	cout << dic.av_dict_count() << endl;
	auto entry = dic.av_dict_get("name", nullptr);
	cout << entry->key << endl;
	cout << entry->value << endl;
}

void test_parse()
{
	int height, width;
	av_parse_video_size(&height, &width, "1920*1080");
	cout << height << ":" << width << endl;
}

int main(void)
{
	return 0;
}
