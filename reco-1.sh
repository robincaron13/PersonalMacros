#!/bin/bash

recoSummary ()  {
    echo;
    echo "=============================================";
    echo $1;
    root -l -q countTracks.C\("MFTAssessment_${1}.root"\)
    #| grep -v "Processing " grep --color=auto Timing reco_${1}.log | grep tracker;
    echo "=============================================";
    echo;
}

plotSummary ()  {
    echo;
    echo "=============================================";
    echo $1;
    root -l -q plot.cpp\("\${1}"\)
    #| grep -v "Processing " grep --color=auto Timing reco_${1}.log | grep tracker;
    echo "=============================================";
    echo;
}

MFTreco ()
{
    NTHREADS=4
    nRBins=${1};
    nPhiBins=${2};
    rCut=${3};
    ZvtxMin=${4}
    ZvtxMax=${5};
    #echo ""
    #echo "==========================================================================================="
    prefix="${nRBins}R_${nPhiBins}Phi_${rCut}RCut_${ZvtxMin}ZMin_${ZvtxMax}ZMax"
    Trkconfig="MFTTracking.RBins=${nRBins};MFTTracking.PhiBins=${nPhiBins};MFTTracking.rCutAtZmin=${rCut};MFTTracking.ZVtxMin=${ZvtxMin};MFTTracking.ZVtxMax=${ZvtxMax};"
    echo $prefix
    #echo MFTTrackingConfig = $Trkconfig
    #time o2-mft-reco-workflow --configKeyValues $Trkconfig --nThreads $NTHREADS | o2-mft-assessment-workflow -b --run > reco_${prefix}.log && mv MFTAssessment.root MFTAssessment_${prefix}.root
    #plotSummary "$prefix"
    #echo "==========================================================================================="
    #echo ""
    
}

R_BINLIST="30 50 70 100 120"
PHI_BINLIST="30 50 70 100 120"

R_CUT=0.1
ZVMIN=-15.
ZVMAX=15.

for R_BINS in $R_BINLIST
do
    for P_BINS in $PHI_BINLIST
    do
        MFTreco $R_BINS $P_BINS $R_CUT $ZVMIN $ZVMAX
    done
done


Z_LIST="10. 12. 15. 18. 20."

#for R_BINS in $R_BINLIST

R_BINS0=100
#P_BINS0=100
#for ZZ in $Z_LIST
#do
#    MFTreco $R_BINS0 $P_BINS0 $R_CUT -$ZZ $ZZ
#done



#ZVMIN=-13.
#ZVMAX=13.
#
#for R_BINS in $R_BINLIST
#do
#    for P_BINS in $PHI_BINLIST
#    do
#        MFTreco $R_BINS $P_BINS $R_CUT $ZVMIN $ZVMAX
#    done
#done
#
#
#ZVMIN=-18.
#ZVMAX=18.
#
#for R_BINS in $R_BINLIST
#do
#    for P_BINS in $PHI_BINLIST
#    do
#        MFTreco $R_BINS $P_BINS $R_CUT $ZVMIN $ZVMAX
#    done
#done
