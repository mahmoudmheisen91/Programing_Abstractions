/*
 * File: sound.cpp
 * ---------------
 * Implementation of the Sound class.
 * 
 * @version 2014/10/08
 * - removed 'using namespace' statement
 * - removed unused include statements
 */

#include "../StanfordCPPLib/sound.h"

#include "../StanfordCPPLib/platform.h"

static Platform *pp = getPlatform();

Sound::Sound(std::string filename) {
    pp->sound_constructor(this, filename);
}

Sound::~Sound() {
    pp->sound_delete(this);
}

void Sound::play() {
    pp->sound_play(this);
}

