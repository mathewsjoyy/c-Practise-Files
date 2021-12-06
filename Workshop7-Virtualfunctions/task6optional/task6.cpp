#include <iostream>
#include <vector>
#include <windows.h>

enum EFrequency {
	keRest = 0,
	keC1 = 131, keCS1 = 139, keD1 = 147, keDS1 = 156, keE1 = 165, keF1 = 175,
	keFS1 = 185, keG1 = 196, keGS1 = 208, keA1 = 220, keAS1 = 233, keB1 = 247,
	keC2 = 262, keCS2 = 277, keD2 = 294, keDS2 = 311, keE2 = 330, keF2 = 349,
	keFS2 = 370, keG2 = 392, keGS2 = 415, keA2 = 440, keAS2 = 466, keB2 = 494,
	keC3 = 523, keCS3 = 554, keD3 = 587, keDS3 = 622, keE3 = 659, keF3 = 698,
	keFS3 = 740, keG3 = 784, keGS3 = 830, keA3 = 880, keAS3 = 932, keB3 = 988,
};

enum EDuration {
	ke16th = 200, ke8th = (ke16th << 1), keQuart = (ke8th << 1),
	keHalf = (keQuart << 1), keWhole = (keQuart << 1)
};


class Note {
public:
    Note(unsigned int uiFrequency, unsigned int uiDuration)
		: muiFrequency(uiFrequency), muiDuration(uiDuration) {};
    virtual void Play() = 0;

    unsigned int muiFrequency;
	unsigned int muiDuration;
};


class CNote : Note {
public:
	CNote(unsigned int uiFrequency, unsigned int uiDuration)
		: Note(uiFrequency, uiDuration) {}
	void Play () override {
		if (muiFrequency > 0) {
			Beep(muiFrequency, muiDuration);
		} else {
			Sleep(muiDuration);
		}
	}
};

class CMelody {
public:
	void AddNote(unsigned int uiFrequency, unsigned int uiDuration) {
		mqNotes.push_back(CNote(uiFrequency, uiDuration));
	}
	void Play () {
		const unsigned int kuiNoteCount = mqNotes.size();
		std::vector<CNote>::iterator qIter;
		for (qIter = mqNotes.begin(); qIter != mqNotes.end(); ++qIter) {
			qIter->Play();
		}
	}
	std::vector<CNote> mqNotes;
};

int main() {

	std::cout << "Setting up and playing a Christmas melody..." << std::endl;

	CMelody aMelody;

	aMelody.AddNote(keA2, ke8th + ke16th);
	aMelody.AddNote(keB2, ke16th);
	aMelody.AddNote(keA2, ke8th);
	aMelody.AddNote(keFS2, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keA2, ke8th + ke16th);
	aMelody.AddNote(keB2, ke16th);
	aMelody.AddNote(keA2, ke8th);
	aMelody.AddNote(keFS2, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keE3, ke8th + ke16th);
	aMelody.AddNote(keDS2, ke16th);
	aMelody.AddNote(keE3, ke8th);
	aMelody.AddNote(keCS3, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keD3, ke8th + ke16th);
	aMelody.AddNote(keCS3, ke16th);
	aMelody.AddNote(keD3, ke8th);
	aMelody.AddNote(keA2, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keB2, keQuart);
	aMelody.AddNote(keB2, ke8th);
	aMelody.AddNote(keD3, ke8th + ke16th);
	aMelody.AddNote(keC3, ke16th);
	aMelody.AddNote(keB2, ke8th);

	aMelody.AddNote(keA2, ke8th + ke16th);
	aMelody.AddNote(keB2, ke16th);
	aMelody.AddNote(keA2, ke8th);
	aMelody.AddNote(keFS2, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keB2, keQuart);
	aMelody.AddNote(keB2, ke8th);
	aMelody.AddNote(keD3, ke8th + ke16th);
	aMelody.AddNote(keCS3, ke16th);
	aMelody.AddNote(keB2, ke8th);

	aMelody.AddNote(keA2, ke8th + ke16th);
	aMelody.AddNote(keB2, ke16th);
	aMelody.AddNote(keA2, ke8th);
	aMelody.AddNote(keFS2, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keCS3, ke8th + ke16th);
	aMelody.AddNote(keCS3, ke16th);
	aMelody.AddNote(keCS3, ke8th);
	aMelody.AddNote(keE3, ke8th + ke16th);
	aMelody.AddNote(keD3, ke16th);
	aMelody.AddNote(keCS3, ke8th);

	aMelody.AddNote(keD3, keQuart + ke8th);
	aMelody.AddNote(keFS3, keQuart);
	aMelody.AddNote(keRest, ke8th);

	aMelody.AddNote(keD3, ke8th + ke16th);
	aMelody.AddNote(keA2, ke16th);
	aMelody.AddNote(keFS2, ke8th);
	aMelody.AddNote(keA2, ke8th + ke16th);
	aMelody.AddNote(keG2, ke16th);
	aMelody.AddNote(keE2, ke8th);

	aMelody.AddNote(keD2, keHalf + ke8th);
	aMelody.AddNote(keRest, ke8th);

	aMelody.Play();

	std::cout << "The end." << std::endl;

	return 0;
}
