#pragma once

#include "audio/AudioClip.h"
#include "core/Phone.h"
#include "tools/ProgressBar.h"
#include "time/BoundedTimeline.h"

BoundedTimeline<Phone> recognizePhones(
	const AudioClip& audioClip,
	double modelWeight,
	int maxThreadCount,
	ProgressSink& progressSink);
