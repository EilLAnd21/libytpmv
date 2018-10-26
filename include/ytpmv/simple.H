#include "common.H"

using namespace std;
namespace ytpmv {
	// load a audio/video source into src
	// params:
	// * audioFile: if not empty, load this audio file into src; formats supported are those supported by your gstreamer installation
	// * videoFile: if not empty, load this video file into src; formats supported are those supported by your gstreamer installation
	// * audioPitch: scale the source's pitch by this amount
	// * audioTempo: scale the source's audio tempo by this amount
	// * videoSpeed: scale the source's video playback rate
	void loadSource(Source& src, string audioFile, string videoFile,
					double audioPitch=1., double audioTempo=1., double videoSpeed=1.);
	extern bool loadAudioOnly;
	
	// load a source and add it to the source library as name; see loadSource()
	Source* addSource(string name, string audioFile, string videoFile,
					double audioPitch=1., double audioTempo=1., double videoSpeed=1.);
	
	// retrieve a source by name from source library
	Source* getSource(string name);
	
	// delete from the beginning of the audio and video clip
	void trimSource(string name, double startTimeSeconds, double lengthSeconds=-1);
	
	
	extern PlaybackSettings defaultSettings;
	
	void parseOptions(int argc, char** argv);
	void play(const vector<AudioSegment>& audio, const vector<VideoSegment>& video, const PlaybackSettings& settings=defaultSettings);
	void render(const vector<AudioSegment>& audio, const vector<VideoSegment>& video, const PlaybackSettings& settings=defaultSettings);
	int run(int argc, char** argv, const vector<AudioSegment>& audio, const vector<VideoSegment>& video, const PlaybackSettings& settings=defaultSettings);
};