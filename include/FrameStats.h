#ifndef FRAMESTATS_H
#define FRAMESTATS_H

namespace ORB_SLAM3
{

// Feature and match counts of one stereo frame, for benchmarking. Filled by Tracking (GrabImageStereo,
// TrackLocalMap, keyframe creation); filling it only reads the tracking results, it does not change them.
struct FrameStats
{
    double timestamp = 0.0;
    int nKeysLeft = 0;       // ORB keypoints extracted in the left image
    int nKeysRight = 0;      // ORB keypoints extracted in the right image
    int nStereoMatches = 0;  // left keypoints with a match in the right image
    int nMapMatches = 0;     // keypoints matched to local map points in TrackLocalMap (before outlier rejection)
    int nInliers = 0;        // map point matches that are inliers of the pose optimization (mnMatchesInliers)
    int state = 0;           // Tracking::eTrackingState after tracking this frame
    bool bKeyFrame = false;  // this frame was inserted as a keyframe
};

} // namespace ORB_SLAM3

#endif // FRAMESTATS_H
