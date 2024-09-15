#include "Plane.h"

/*
        // charge
        // plane.notify.play_tune("MFT180MLL8O2CEMNGT118O3C.O2L16G.L4MLO3C");

        // rock_you
        // plane.notify.play_tune("MFT180MLO3L2GF#EDMSL4EE");
       
        // jump
        // plane.notify.play_tune("MFT144MLO3L8DP4EP4CP4CP8DP8L4D.L8EP4CP8O2L4AMNGL2G");

        // boo
        // plane.notify.play_tune("MFT150MSO2L8E-.E-C.MNFL4E-C");

        // bob_barker
        // plane.notify.play_tune("MFT120MLO2L16FP16<GP16F>L2CP8.L16D<P16B-P16GL2>CP4L16CL8CL16E-L16FL8FL16E-FL8FL16E-L8F.L16DP16CP16<B->L2C");

        // star-wars
        // plane.notify.play_tune("MFT100O3L4F#F#F#L8D.L16AL4F#L8D.L16AL2F#O4L4C#C#C#L8D.O3L16AL4FL8D.L16AL2F#");
*/

void Plane::play_indicator(uint8_t flag)
{

    switch (flag)
    {
    case Plane::AUDIO_INDICATOR::IPLS_UNHEALTHY:
        plane.notify.play_tune("MFT144MLO3L8D");
        break;
    
    default:
        break;
    }
    
}