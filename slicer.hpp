/*
 * BASIC SLICER
 *
 * by MASOOD
 * adapted from Python code by Jennifer Jacobs
 * for her Computational Fabrication course in
 * UCSB's Media Arts & Technology department..
 * 
 * Initiated: 4/27/2021
 * Last updated: 5/29/2021
 * 
 * */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

#include <opencv2/core/matx.hpp>

#include "common.hpp"
#include "print.hpp"
#include "layer.hpp"

#define LOG(msg) \
    std::cout << msg << std::endl

#ifndef _SLICER_H_
#define _SLICER_H_

class Slicer
{
public:
    Slicer(double bedWidth, double bedDepth, double maxHeight, double layerHeight, double bedTemp, double nozzleTemp, Print &print);

    // Any public data/members your class will need should be declared here.
    std::string output;
    std::string filePath;

    Print print;

    double bedWidth = 0.0;
    double bedDepth = 0.0;
    double maxHeight = 0.0;

    int bedTemp = 0.0;
    int nozzleTemp = 0.0;

    double zOffset = 0.2;

    double minExtrusion = 0.2;
    double maxExtrusion = 1.0;

    double layerHeight = 0.33;
    double nozzleWidth = 0.4;
    double retAmount = 6.0;
    double retSpeed = 1200.0;
    double printSpeed = 250.0;
    double printSpeedHigh = 1000.0;

    // Any methods your class needs go here.
    void apply();
    void test();

private:
    Slicer();

    void makeGcodeInfo(std::vector<std::string> &strBuff);
    void makeGcodeHeatSettings(std::vector<std::string> &strBuff);
    void makeGcodeStartupSettings(std::vector<std::string> &strBuff);

    std::string makeRetraction(double amount, double speed, int sign);
    std::string centerPrint(double printWidth, double);
    double calcExtrusion(double ext_multiplier, cv::Point2d to, cv::Point2d from);
    std::string makeGcodePoints(cv::Point2d from, cv::Point2d to, unsigned int color);
    std::string makeGcodeSpeed(cv::Point2d from, cv::Point2d to, double speed, unsigned int color);
    std::string makeGcode(cv::Point2d to);
    std::string endGcode();

    void writeFile(std::string str, std::string path);
};

#endif