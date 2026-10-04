#include <stdio.h> 
#include <opencv2/opencv.hpp>
#include <iostream> 

int main(int argc, char** argv)
{

    std::string pipeline = "libcamerasrc !"
    "video/x-raw, format = RGB, width=640, height=480 ! "
    "videoconvert ! "
    "appsink drop=true max-buffers=1 sync=false";

    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);


    if(!cap.isOpened())
    {
        std::cerr << "Error opening video stream or file\n" << std::endl;
        return -1;
    }

    else
    {
        std::cout << "camera ouverte\n" << std::endl;
    }

    

    std::cout << "Appuyez sur 'Echape' pour quitter la fenetre\n" << std::endl;

    cv::Mat frame; 
    
    while(true)
    {

        cap >> frame;

        if(frame.empty())
        {
            std::cerr <<"Erreur : image vide" << std::endl;
            break;
        }


        cv::imshow("Camera1", frame);

        if(cv::waitKey(10) == 27)
        {

            break;
        }
    }

    cap.release();
    
    cv::destroyAllWindows();

    return 0;
}
//test modification 
//test modification 2 