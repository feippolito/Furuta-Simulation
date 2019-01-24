function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/In1 */
	this.urlHashMap["Furuta_Control_mbed:852"] = "Furuta_Control_mbed.c:261,274,302,314&Furuta_Control_mbed.h:32";
	/* <Root>/Constant */
	this.urlHashMap["Furuta_Control_mbed:846"] = "Furuta_Control_mbed.c:353";
	/* <Root>/Constant1 */
	this.urlHashMap["Furuta_Control_mbed:848"] = "Furuta_Control_mbed.c:354";
	/* <Root>/Demux */
	this.urlHashMap["Furuta_Control_mbed:858"] = "msg=&block=Furuta_Control_mbed:858";
	/* <Root>/Divide */
	this.urlHashMap["Furuta_Control_mbed:847"] = "Furuta_Control_mbed.c:356";
	/* <Root>/Feedback control */
	this.urlHashMap["Furuta_Control_mbed:518"] = "Furuta_Control_mbed.c:270,296";
	/* <Root>/Gain */
	this.urlHashMap["Furuta_Control_mbed:843"] = "Furuta_Control_mbed.c:355";
	/* <Root>/If */
	this.urlHashMap["Furuta_Control_mbed:517"] = "Furuta_Control_mbed.c:268,350";
	/* <Root>/Merge */
	this.urlHashMap["Furuta_Control_mbed:526"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Furuta_Control_mbed:526";
	/* <Root>/Sum */
	this.urlHashMap["Furuta_Control_mbed:845"] = "Furuta_Control_mbed.c:357";
	/* <Root>/Swing Up */
	this.urlHashMap["Furuta_Control_mbed:522"] = "Furuta_Control_mbed.c:298,347";
	/* <Root>/Vector
Concatenate3 */
	this.urlHashMap["Furuta_Control_mbed:410"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Furuta_Control_mbed:410";
	/* <Root>/Out1 */
	this.urlHashMap["Furuta_Control_mbed:849"] = "Furuta_Control_mbed.c:352&Furuta_Control_mbed.h:37";
	/* <S1>/Action Port */
	this.urlHashMap["Furuta_Control_mbed:520"] = "Furuta_Control_mbed.c:271";
	/* <S1>/Gain */
	this.urlHashMap["Furuta_Control_mbed:390"] = "Furuta_Control_mbed.c:273,285";
	/* <S1>/Saturation */
	this.urlHashMap["Furuta_Control_mbed:743"] = "Furuta_Control_mbed.c:284,295";
	/* <S2>/Gain2 */
	this.urlHashMap["Furuta_Control_mbed:591"] = "Furuta_Control_mbed.c:258";
	/* <S3>/Action Port */
	this.urlHashMap["Furuta_Control_mbed:524"] = "Furuta_Control_mbed.c:299";
	/* <S3>/Abs */
	this.urlHashMap["Furuta_Control_mbed:480"] = "Furuta_Control_mbed.c:310";
	/* <S3>/Fcn */
	this.urlHashMap["Furuta_Control_mbed:482"] = "Furuta_Control_mbed.c:307";
	/* <S3>/Gain */
	this.urlHashMap["Furuta_Control_mbed:483"] = "Furuta_Control_mbed.c:301";
	/* <S3>/Gain1 */
	this.urlHashMap["Furuta_Control_mbed:484"] = "msg=rtwMsg_SimulationReducedBlock&block=Furuta_Control_mbed:484";
	/* <S3>/Mut */
	this.urlHashMap["Furuta_Control_mbed:485"] = "Furuta_Control_mbed.c:313";
	/* <S3>/Mut1 */
	this.urlHashMap["Furuta_Control_mbed:486"] = "Furuta_Control_mbed.c:334";
	/* <S3>/Saturation */
	this.urlHashMap["Furuta_Control_mbed:487"] = "Furuta_Control_mbed.c:337,346";
	/* <S3>/Sign */
	this.urlHashMap["Furuta_Control_mbed:488"] = "Furuta_Control_mbed.c:321,332";
	/* <S3>/Trigonometric
Function */
	this.urlHashMap["Furuta_Control_mbed:506"] = "Furuta_Control_mbed.c:317";
	/* <S4>/2pi */
	this.urlHashMap["Furuta_Control_mbed:585"] = "Furuta_Control_mbed.c:259";
	/* <S4>/Add */
	this.urlHashMap["Furuta_Control_mbed:586"] = "Furuta_Control_mbed.c:263";
	/* <S4>/Constant */
	this.urlHashMap["Furuta_Control_mbed:587"] = "Furuta_Control_mbed.c:260";
	/* <S4>/Math
Function */
	this.urlHashMap["Furuta_Control_mbed:588"] = "Furuta_Control_mbed.c:262";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Furuta_Control_mbed"};
	this.sidHashMap["Furuta_Control_mbed"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "Furuta_Control_mbed:518"};
	this.sidHashMap["Furuta_Control_mbed:518"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "Furuta_Control_mbed:581"};
	this.sidHashMap["Furuta_Control_mbed:581"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "Furuta_Control_mbed:522"};
	this.sidHashMap["Furuta_Control_mbed:522"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "Furuta_Control_mbed:583"};
	this.sidHashMap["Furuta_Control_mbed:583"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<Root>/In1"] = {sid: "Furuta_Control_mbed:852"};
	this.sidHashMap["Furuta_Control_mbed:852"] = {rtwname: "<Root>/In1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "Furuta_Control_mbed:846"};
	this.sidHashMap["Furuta_Control_mbed:846"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "Furuta_Control_mbed:848"};
	this.sidHashMap["Furuta_Control_mbed:848"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Demux"] = {sid: "Furuta_Control_mbed:858"};
	this.sidHashMap["Furuta_Control_mbed:858"] = {rtwname: "<Root>/Demux"};
	this.rtwnameHashMap["<Root>/Divide"] = {sid: "Furuta_Control_mbed:847"};
	this.sidHashMap["Furuta_Control_mbed:847"] = {rtwname: "<Root>/Divide"};
	this.rtwnameHashMap["<Root>/Feedback control"] = {sid: "Furuta_Control_mbed:518"};
	this.sidHashMap["Furuta_Control_mbed:518"] = {rtwname: "<Root>/Feedback control"};
	this.rtwnameHashMap["<Root>/From"] = {sid: "Furuta_Control_mbed:844"};
	this.sidHashMap["Furuta_Control_mbed:844"] = {rtwname: "<Root>/From"};
	this.rtwnameHashMap["<Root>/From15"] = {sid: "Furuta_Control_mbed:412"};
	this.sidHashMap["Furuta_Control_mbed:412"] = {rtwname: "<Root>/From15"};
	this.rtwnameHashMap["<Root>/From18"] = {sid: "Furuta_Control_mbed:384"};
	this.sidHashMap["Furuta_Control_mbed:384"] = {rtwname: "<Root>/From18"};
	this.rtwnameHashMap["<Root>/From19"] = {sid: "Furuta_Control_mbed:592"};
	this.sidHashMap["Furuta_Control_mbed:592"] = {rtwname: "<Root>/From19"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "Furuta_Control_mbed:843"};
	this.sidHashMap["Furuta_Control_mbed:843"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/Goto"] = {sid: "Furuta_Control_mbed:857"};
	this.sidHashMap["Furuta_Control_mbed:857"] = {rtwname: "<Root>/Goto"};
	this.rtwnameHashMap["<Root>/Goto10"] = {sid: "Furuta_Control_mbed:411"};
	this.sidHashMap["Furuta_Control_mbed:411"] = {rtwname: "<Root>/Goto10"};
	this.rtwnameHashMap["<Root>/Goto8"] = {sid: "Furuta_Control_mbed:374"};
	this.sidHashMap["Furuta_Control_mbed:374"] = {rtwname: "<Root>/Goto8"};
	this.rtwnameHashMap["<Root>/Goto9"] = {sid: "Furuta_Control_mbed:382"};
	this.sidHashMap["Furuta_Control_mbed:382"] = {rtwname: "<Root>/Goto9"};
	this.rtwnameHashMap["<Root>/If"] = {sid: "Furuta_Control_mbed:517"};
	this.sidHashMap["Furuta_Control_mbed:517"] = {rtwname: "<Root>/If"};
	this.rtwnameHashMap["<Root>/Merge"] = {sid: "Furuta_Control_mbed:526"};
	this.sidHashMap["Furuta_Control_mbed:526"] = {rtwname: "<Root>/Merge"};
	this.rtwnameHashMap["<Root>/Rad2Grad1"] = {sid: "Furuta_Control_mbed:581"};
	this.sidHashMap["Furuta_Control_mbed:581"] = {rtwname: "<Root>/Rad2Grad1"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "Furuta_Control_mbed:845"};
	this.sidHashMap["Furuta_Control_mbed:845"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Swing Up"] = {sid: "Furuta_Control_mbed:522"};
	this.sidHashMap["Furuta_Control_mbed:522"] = {rtwname: "<Root>/Swing Up"};
	this.rtwnameHashMap["<Root>/Vector Concatenate3"] = {sid: "Furuta_Control_mbed:410"};
	this.sidHashMap["Furuta_Control_mbed:410"] = {rtwname: "<Root>/Vector Concatenate3"};
	this.rtwnameHashMap["<Root>/Out1"] = {sid: "Furuta_Control_mbed:849"};
	this.sidHashMap["Furuta_Control_mbed:849"] = {rtwname: "<Root>/Out1"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "Furuta_Control_mbed:519"};
	this.sidHashMap["Furuta_Control_mbed:519"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Action Port"] = {sid: "Furuta_Control_mbed:520"};
	this.sidHashMap["Furuta_Control_mbed:520"] = {rtwname: "<S1>/Action Port"};
	this.rtwnameHashMap["<S1>/Gain"] = {sid: "Furuta_Control_mbed:390"};
	this.sidHashMap["Furuta_Control_mbed:390"] = {rtwname: "<S1>/Gain"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "Furuta_Control_mbed:743"};
	this.sidHashMap["Furuta_Control_mbed:743"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "Furuta_Control_mbed:521"};
	this.sidHashMap["Furuta_Control_mbed:521"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S2>/ThetaRad"] = {sid: "Furuta_Control_mbed:582"};
	this.sidHashMap["Furuta_Control_mbed:582"] = {rtwname: "<S2>/ThetaRad"};
	this.rtwnameHashMap["<S2>/0-2pi"] = {sid: "Furuta_Control_mbed:583"};
	this.sidHashMap["Furuta_Control_mbed:583"] = {rtwname: "<S2>/0-2pi"};
	this.rtwnameHashMap["<S2>/Gain2"] = {sid: "Furuta_Control_mbed:591"};
	this.sidHashMap["Furuta_Control_mbed:591"] = {rtwname: "<S2>/Gain2"};
	this.rtwnameHashMap["<S2>/ThetaGrad"] = {sid: "Furuta_Control_mbed:590"};
	this.sidHashMap["Furuta_Control_mbed:590"] = {rtwname: "<S2>/ThetaGrad"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "Furuta_Control_mbed:523"};
	this.sidHashMap["Furuta_Control_mbed:523"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/Action Port"] = {sid: "Furuta_Control_mbed:524"};
	this.sidHashMap["Furuta_Control_mbed:524"] = {rtwname: "<S3>/Action Port"};
	this.rtwnameHashMap["<S3>/Abs"] = {sid: "Furuta_Control_mbed:480"};
	this.sidHashMap["Furuta_Control_mbed:480"] = {rtwname: "<S3>/Abs"};
	this.rtwnameHashMap["<S3>/Demux"] = {sid: "Furuta_Control_mbed:481"};
	this.sidHashMap["Furuta_Control_mbed:481"] = {rtwname: "<S3>/Demux"};
	this.rtwnameHashMap["<S3>/Fcn"] = {sid: "Furuta_Control_mbed:482"};
	this.sidHashMap["Furuta_Control_mbed:482"] = {rtwname: "<S3>/Fcn"};
	this.rtwnameHashMap["<S3>/Gain"] = {sid: "Furuta_Control_mbed:483"};
	this.sidHashMap["Furuta_Control_mbed:483"] = {rtwname: "<S3>/Gain"};
	this.rtwnameHashMap["<S3>/Gain1"] = {sid: "Furuta_Control_mbed:484"};
	this.sidHashMap["Furuta_Control_mbed:484"] = {rtwname: "<S3>/Gain1"};
	this.rtwnameHashMap["<S3>/Mut"] = {sid: "Furuta_Control_mbed:485"};
	this.sidHashMap["Furuta_Control_mbed:485"] = {rtwname: "<S3>/Mut"};
	this.rtwnameHashMap["<S3>/Mut1"] = {sid: "Furuta_Control_mbed:486"};
	this.sidHashMap["Furuta_Control_mbed:486"] = {rtwname: "<S3>/Mut1"};
	this.rtwnameHashMap["<S3>/Saturation"] = {sid: "Furuta_Control_mbed:487"};
	this.sidHashMap["Furuta_Control_mbed:487"] = {rtwname: "<S3>/Saturation"};
	this.rtwnameHashMap["<S3>/Sign"] = {sid: "Furuta_Control_mbed:488"};
	this.sidHashMap["Furuta_Control_mbed:488"] = {rtwname: "<S3>/Sign"};
	this.rtwnameHashMap["<S3>/Terminator1"] = {sid: "Furuta_Control_mbed:508"};
	this.sidHashMap["Furuta_Control_mbed:508"] = {rtwname: "<S3>/Terminator1"};
	this.rtwnameHashMap["<S3>/Terminator2"] = {sid: "Furuta_Control_mbed:505"};
	this.sidHashMap["Furuta_Control_mbed:505"] = {rtwname: "<S3>/Terminator2"};
	this.rtwnameHashMap["<S3>/Trigonometric Function"] = {sid: "Furuta_Control_mbed:506"};
	this.sidHashMap["Furuta_Control_mbed:506"] = {rtwname: "<S3>/Trigonometric Function"};
	this.rtwnameHashMap["<S3>/Out1"] = {sid: "Furuta_Control_mbed:525"};
	this.sidHashMap["Furuta_Control_mbed:525"] = {rtwname: "<S3>/Out1"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "Furuta_Control_mbed:584"};
	this.sidHashMap["Furuta_Control_mbed:584"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/2pi"] = {sid: "Furuta_Control_mbed:585"};
	this.sidHashMap["Furuta_Control_mbed:585"] = {rtwname: "<S4>/2pi"};
	this.rtwnameHashMap["<S4>/Add"] = {sid: "Furuta_Control_mbed:586"};
	this.sidHashMap["Furuta_Control_mbed:586"] = {rtwname: "<S4>/Add"};
	this.rtwnameHashMap["<S4>/Constant"] = {sid: "Furuta_Control_mbed:587"};
	this.sidHashMap["Furuta_Control_mbed:587"] = {rtwname: "<S4>/Constant"};
	this.rtwnameHashMap["<S4>/Math Function"] = {sid: "Furuta_Control_mbed:588"};
	this.sidHashMap["Furuta_Control_mbed:588"] = {rtwname: "<S4>/Math Function"};
	this.rtwnameHashMap["<S4>/Out1"] = {sid: "Furuta_Control_mbed:589"};
	this.sidHashMap["Furuta_Control_mbed:589"] = {rtwname: "<S4>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
