#ifndef FRAME_H
#define FRAME_H

#include <opencv2/core.hpp>

class Frame
{
public:
	enum KeyPointDetectionMethod
	{
		CvGoodPointsMethod,
		ORBMethod
	};

	Frame();
	Frame(const Frame& other);
	Frame& operator=(const Frame& other);

    const cv::Mat& descriptors() const;

    void extractFeatures(const cv::Mat& image, KeyPointDetectionMethod method = CvGoodPointsMethod);
	void setRecordedSpeed(float recordedSpeed);
	void setObservedSpeed(float observedSpeed);

	float recordedSpeed() const;
	float observedSpeed() const;

    const std::vector<cv::KeyPoint>& extractedFeatures() const;

	int width() const;
	int height() const;

private:
	int _width;
	int _height;

    void useOrb(const cv::Mat& img);
    void useCvGoodFeatures(const cv::Mat& img);

    std::vector<cv::KeyPoint> _extractedFeatures;
    cv::Mat _descriptors;

	float _recordedSpeed;
	float _observedSpeed;
};

#endif // FRAME_H
