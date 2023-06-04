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

extern "C"
{
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
}

int main(void)
{
	fstream fs{"./temp.txt", ios_base::out | ios_base::in | ios_base::trunc};
	fs << "黄锦灿" << endl;
	fs.flush();
	fs.seekg(0);
	string read_str;
	fs >> read_str;
	cout << read_str << endl;
	return 0;
}
