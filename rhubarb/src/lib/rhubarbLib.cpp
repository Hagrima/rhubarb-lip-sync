#include "rhubarbLib.h"
#include "core/Phone.h"
#include "recognition/phoneRecognition.h"
#include "tools/textFiles.h"
#include "animation/mouthAnimation.h"
#include "audio/audioFileReading.h"

using boost::optional;
using std::string;
using boost::filesystem::path;
using std::unique_ptr;

JoiningContinuousTimeline<Shape> animateAudioClip(
	const AudioClip& audioClip,
	double modelWeight,
	const ShapeSet& targetShapeSet,
	int maxThreadCount,
	ProgressSink& progressSink)
{
	BoundedTimeline<Phone> phones = recognizePhones(audioClip, modelWeight, maxThreadCount, progressSink);
	JoiningContinuousTimeline<Shape> result = animate(phones, targetShapeSet);
	return result;
}

JoiningContinuousTimeline<Shape> animateWaveFile(
	path filePath,
	double modelWeight,
	const ShapeSet& targetShapeSet,
	int maxThreadCount,
	ProgressSink& progressSink)
{
	const auto audioClip = createAudioFileClip(filePath);
	return animateAudioClip(*audioClip, modelWeight, targetShapeSet, maxThreadCount, progressSink);
}
