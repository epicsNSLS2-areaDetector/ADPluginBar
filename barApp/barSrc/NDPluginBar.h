#ifndef NDPlufinBar_H
#define NDPluginBar_H

#include "NDPluginDriver.h"

#define BAR_VERSION      0
#define BAR_REVISION     0
#define BAR_MODIFICATION 0

//Here I will define all of the output data types once the database is written
#define NDPluginBarBarcodeMessageString "BARCODE_MESSAGE" //waveform
#define NDPluginBarBarcodeTypeString "BARCODE_TYPE" //waveform
#define NDPluginBarNumberCodesString "NUMBER_CODES" //asynInt32
#define NDPluginBarBacodeFoundString "BARCODE_FOUND" //asynInt32
#define NDPluginBarUpperLeftString "UPPER_LEFT" //asynInt32
#define NDPluginBarUpperRightString "UPPER_RIGHT" //asynInt32
#define NDPluginBarLowerLeftString "LOWER_LEFT" //asynInt32
#define NDPluginBarLowerLeftString "LOWER_LEFT" //asynInt32


//class that does barcode readings
class NDPluginBar : public NDPluginDriver {

	public:
		NDPluginBar(const char *portName, int queueSize, int blockingCallbacks,
			const char* NDArrayPort, int NDArrayAddr, int maxBuffers,
			size_t maxMemory, int priority, int stackSize);
		void processCallBacks(NDArray *pArray);

	protected:

		//in this section, once i define the database values, I will have to define them here
		//message contained in bar code
		char* NDPluginBarBarcodeMessage;

		//type of bar code i.e. QR, BAR
		char* NDPluginBarBarcodeType;
		
		//if there is a bar code found
		int NDPluginBarBarcodeFound;

		//number of codes found
		int NDPluginBarNumberCodes;

		//upper left pixel of found bar code
		int NDPluginBarUpperLeft;
		
		//upper right pixel of found bar code
		int NDPluginBarUpperRight;

		//lower left pixel of found bar code
		int NDPluginBarLowerLeft;

		//lower right pixel of found bar code
		int NDPluginBarLowerRight;
		
	private:

};

#endif
