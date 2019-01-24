function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:35,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:71,type:"fcn"};
this.def["rtU"] = {file: "Furuta_Control_mbed_c.html",line:22,type:"var"};
this.def["rtY"] = {file: "Furuta_Control_mbed_c.html",line:25,type:"var"};
this.def["BigEndianIEEEDouble"] = {file: "Furuta_Control_mbed_c.html",line:45,type:"type"};
this.def["LittleEndianIEEEDouble"] = {file: "Furuta_Control_mbed_c.html",line:52,type:"type"};
this.def["IEEESingle"] = {file: "Furuta_Control_mbed_c.html",line:59,type:"type"};
this.def["rtInf"] = {file: "Furuta_Control_mbed_c.html",line:61,type:"var"};
this.def["rtMinusInf"] = {file: "Furuta_Control_mbed_c.html",line:62,type:"var"};
this.def["rtNaN"] = {file: "Furuta_Control_mbed_c.html",line:63,type:"var"};
this.def["rtInfF"] = {file: "Furuta_Control_mbed_c.html",line:64,type:"var"};
this.def["rtMinusInfF"] = {file: "Furuta_Control_mbed_c.html",line:65,type:"var"};
this.def["rtNaNF"] = {file: "Furuta_Control_mbed_c.html",line:66,type:"var"};
this.def["rtGetNaN"] = {file: "Furuta_Control_mbed_c.html",line:76,type:"fcn"};
this.def["rtGetNaNF"] = {file: "Furuta_Control_mbed_c.html",line:100,type:"fcn"};
this.def["rt_InitInfAndNaN"] = {file: "Furuta_Control_mbed_c.html",line:112,type:"fcn"};
this.def["rtIsInf"] = {file: "Furuta_Control_mbed_c.html",line:124,type:"fcn"};
this.def["rtIsInfF"] = {file: "Furuta_Control_mbed_c.html",line:130,type:"fcn"};
this.def["rtIsNaN"] = {file: "Furuta_Control_mbed_c.html",line:136,type:"fcn"};
this.def["rtIsNaNF"] = {file: "Furuta_Control_mbed_c.html",line:142,type:"fcn"};
this.def["rtGetInf"] = {file: "Furuta_Control_mbed_c.html",line:151,type:"fcn"};
this.def["rtGetInfF"] = {file: "Furuta_Control_mbed_c.html",line:175,type:"fcn"};
this.def["rtGetMinusInf"] = {file: "Furuta_Control_mbed_c.html",line:186,type:"fcn"};
this.def["rtGetMinusInfF"] = {file: "Furuta_Control_mbed_c.html",line:210,type:"fcn"};
this.def["rt_modd_snf"] = {file: "Furuta_Control_mbed_c.html",line:217,type:"fcn"};
this.def["Furuta_Control_mbed_step"] = {file: "Furuta_Control_mbed_c.html",line:253,type:"fcn"};
this.def["Furuta_Control_mbed_initialize"] = {file: "Furuta_Control_mbed_c.html",line:363,type:"fcn"};
this.def["ExtU"] = {file: "Furuta_Control_mbed_h.html",line:33,type:"type"};
this.def["ExtY"] = {file: "Furuta_Control_mbed_h.html",line:38,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Furuta_Control_mbed_c.html"] = "../Furuta_Control_mbed.c";
	this.html2Root["Furuta_Control_mbed_c.html"] = "Furuta_Control_mbed_c.html";
	this.html2SrcPath["Furuta_Control_mbed_h.html"] = "../Furuta_Control_mbed.h";
	this.html2Root["Furuta_Control_mbed_h.html"] = "Furuta_Control_mbed_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Furuta_Control_mbed_c.html","Furuta_Control_mbed_h.html","rtwtypes_h.html"];
