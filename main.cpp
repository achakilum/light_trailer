#include <cstdlib>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char ** argv)
{
	cv::VideoCapture webcamCapture(0); // open the default camera
	if(!webcamCapture.isOpened())
	{
		std::cerr << "Failed to open the default webcam" << std::endl;
		return -1;
	}  // check if we succeeded


	cv::Mat lightPainting;
	int recordState = 0;

	while (recordState < 2)
	{
		cv::Mat frame;
		webcamCapture >> frame; // get a new frame from camera

		lightPainting = (recordState > 0) ? cv::max(lightPainting, frame) : frame;
		cv::imshow("Webcam footage", lightPainting);

		std::cout << lightPainting.rows << " " << lightPainting.cols << " " << lightPainting.cn << std::endl;

		if(cv::waitKey(33) >= 0)
		{
			recordState++;
			switch (recordState)
			{
				case 1:
					std::cout << "Recording started" << std::endl;
					break;
				case 2:
					std::cout << "Recording ended" << std::endl;
					break;
			}
		}
	}

	cv::destroyWindow("Webcam footage");
	cv::imshow("Final image", lightPainting);
	cv::waitKey(0);

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}
