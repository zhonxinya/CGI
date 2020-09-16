var DEBUG = false;

var HelpOptionsVar = "width=480,height=420,scrollbars,toolbar,resizable,dependent=yes";
var GlossOptionsVar = "width=420,height=180,scrollbars,toolbar,resizable,dependent=yes";
var bigsub   = "width=560,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var smallsub = "width=500,height=360,scrollbars,resizable,dependent=yes";
var key_sub = "width=350,height=250,scrollbars,resizable,dependent=yes";
var sersub   = "width=500,height=380,scrollbars,resizable,status,dependent=yes";
var multisub   = "width=630,height=470,scrollbars,menubar,resizable,status,dependent=yes";
var hugesub   = "width=700,height=560,scrollbars,menubar,resizable,status,dependent=yes";
var prosub   = "width=700,height=360,scrollbars,menubar,resizable,status,dependent=yes";
var logsub   = "width=620,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var statsub  = "width=700,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var uamtimewin = "left=100,top=100,height=200,width=200,status=no,toolbar=no,menubar=no,location=no,resizable";
var devsub   = "width=650,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var statissub   = "width=750,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var helpWinVar = null;
var glossWinVar = null;
var datSubWinVar = null;
var ValidStr = 'abcdefghijklmnopqrstuvwxyz-';
var ValidStr_ddns = 'abcdefghijklmnopqrstuvwxyz-1234567890';
var hex_str = "ABCDEFabcdef0123456789";
var input_hidden = "********";
var num_str = "0123456789";

function showMsg()
{
	var msgVar=document.forms["main"].message.value;
	if (msgVar.length > 1)
		alert(msgVar);
}
function dw(message)
{
	document.write(message);
}
function checkMsg(msg)
{
        if(msg.length > 1)
        {
                alert(msg);
                return false;
        }
        return true;
}

function badLeaseTime(lease1, lease2, lease3, lease4)   // lease fields
{
	if(!(isInteger(lease1.value,0,365,false))) return true;
	if(!(isInteger(lease2.value,0,23,false))) return true;
	if(!(isInteger(lease3.value,0,59,false))) return true;
	if(!(isInteger(lease4.value,0,59,false))) return true;
   	return false;
}

function badSubnetIP(ip1, ip2, ip3, ip4, max)   // ip fields
{
	if(!(isInteger(ip1.value,1,254,false))) return true;
	if(!(isInteger(ip2.value,0,255,false))) return true;
	if(!(isInteger(ip3.value,0,255,false))) return true;
	if(!(isInteger(ip4.value,0,max,false))) return true;
   	return false;
}


function closeWin(win_var)
{
	if ( ((win_var != null) && (win_var.close)) || ((win_var != null) && (win_var.closed==false)) )
		win_var.close();
}

//function openHelpWin(file_name)
//{
//   helpWinVar = window.open(file_name,'help_win',HelpOptionsVar);
//   if (helpWinVar.focus)
//		setTimeout('helpWinVar.focus()',200);
//}

function openGlossWin()
{
	glossWinVar = window.open('','gloss_win',GlossOptionsVar);
	if (glossWinVar.focus)
		setTimeout('glossWinVar.focus()',200);
}

function openDataSubWin(filename,win_type)
{
	closeWin(datSubWinVar);
	datSubWinVar = window.open(filename,'datasub_win',win_type);
	if (datSubWinVar.focus)
		setTimeout('datSubWinVar.focus()',200);
}

function closeSubWins()
{
	closeWin(helpWinVar);
	closeWin(glossWinVar);
	closeWin(datSubWinVar);
}
function openDataSubWin(filename,win_type)
{
	closeWin(datSubWinVar);
	datSubWinVar = window.open(filename,'datasub_win',win_type);
	if (datSubWinVar.focus)
		setTimeout('datSubWinVar.focus()',200);
}

function showHelp(helpfile)
{
	if(top.frames.length == 0)
		return;
	top.helpframe.location.href = helpfile;
}

function checkBlank(fieldObj, fname)
{
	var msg = "";
	if (fieldObj.value.length < 1)
		msg = addstr(getErrorMsgByVar("gsm_blank"),fname);
	return msg;
}

function checkNoBlanks(fObj, fname)
{
	var space = " ";
 	if (fObj.value.indexOf(space) >= 0 )
			return addstr(getErrorMsgByVar("gsm_space"),fname);
	else return "";
}

function checkAllSpaces(fieldObj, fname)
{
	var msg = "";
	if(fieldObj.value.length == 0)
		return "";
	var tstr = makeStr(fieldObj.value.length," ");
	if (tstr == fieldObj.value)
		msg = addstr(msg_allspaces,fname);
	return msg;
}

function checkAllNumChars(inStr) //check all chars are numeric
{
    for (var i=0; i < inStr.length; i++)
    if (num_str.indexOf(inStr.charAt(i)) < 0)
    {       
			return false;
	}	
    return true;
}


function checkValid(text_input_field, field_name, Valid_Str, max_size, mustFill)
{
	var error_msg= "";
	var size = text_input_field.value.length;
	var str = text_input_field.value;

	if ((mustFill) && (size != max_size) )
		error_msg = addstr(msg_blank_pin,field_name);
 	for (var i=0; i < size; i++)
  	{
    	if (!(Valid_Str.indexOf(str.charAt(i)) >= 0))
    	{
			error_msg = addstr(msg_invalid,field_name,Valid_Str);
			break;
    	}
  	}
  	return error_msg;
}

function checkInt(text_input_field, field_name, min_value, max_value, required)
// NOTE: Doesn't allow negative numbers, required is true/false
{
	var str = text_input_field.value;
	var error_msg= "";

	if (text_input_field.value.length==0) // blank
	{
		if (required)
			error_msg = addstr(getErrorMsgByVar("gsm_blank"),field_name);
	}
	else // not blank, check contents
	{
		for (var i=0; i < str.length; i++)
		{
			if((i == 0) && (str.charAt(i) == '-'))
			{
				continue;
			}
			if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
				error_msg = addstr(getErrorMsgByVar("gsm_check_invalid"),field_name);
		}
		if (error_msg.length < 2) // don't parse if invalid
		{
			var int_value = parseInt(str,10);
			if (int_value < min_value)
				error_msg = addstr(getErrorMsgByVar("gsm_greater"),field_name,(min_value - 1));
			if (int_value > max_value)
				error_msg = addstr(getErrorMsgByVar("gsm_less"),field_name,(max_value + 1));
		}
	}
	return(error_msg);
}

function blankIP(fn) // true if 0 or blank
{
	return ( (fn.value == "") || (fn.value == "0") )
}

function blankIP4(ip1, ip2, ip3, ip4) // ip fields, true if 0 or blank
{
return ((ip1.value == "" || ip1.value == "0")
	 && (ip2.value == "" || ip2.value == "0")
	 && (ip3.value == "" || ip3.value == "0")
	 && (ip4.value == "" || ip4.value == "0"))
}


function checkIp(ip1,ip2,ip3,ip4,msg,rq_flag)
{
	if( (rq_flag == false) && blankIP(ip1) && blankIP(ip2) && blankIP(ip3) && blankIP(ip4) )
		return "";
	var errmsg =  ""; //checkInt(ip1,msg,1,254,true);
	if (ip1.value < 1 || ip1.value > 223 || 127 == ip1.value)
	{
		errmsg =  addstr(getErrorMsgByVar("gsm_validIP1"), msg);
		return errmsg;
	}
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip1,msg,1,223,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip2,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip3,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip4,msg,1,254,true);
	errmsg =  (errmsg.length > 1) ? addstr(getErrorMsgByVar("gsm_validIP"),msg) : "";
	return errmsg;
}
function badIP(ip1, ip2, ip3, ip4, max)   // ip fields
{
	if(!(isInteger(ip1.value,1,254,false))) return true;
	if(!(isInteger(ip2.value,0,255,false))) return true;
	if(!(isInteger(ip3.value,0,255,false))) return true;
	if(!(isInteger(ip4.value,1,max,false))) return true;
   	return false;
}


function checkLanIp(ip1,ip2,ip3,ip4,msg,rq_flag)
{
	if( (rq_flag == false) && blankIP(ip1) && blankIP(ip2) && blankIP(ip3) && blankIP(ip4) )
		return "";
    var errmsg = "";
    if(parseInt(ip1.value, 10) == 127)
    {
        errmsg = msg;
    }
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip1,msg,1,223,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip2,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip3,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip4,msg,1,254,true);
	errmsg =  (errmsg.length > 1) ? addstr(getErrorMsgByVar("gsm_validIP"),msg) : "";
	return errmsg;
}

function checkLanNetMask(field)
{
    var values = new Array("0","128","192","224","240","248","252");
    var i;

    for (i=0; i<values.length; i++) {
        if (field.value == values[i])
            break;
    }
    if (i >= values.length)
        return msg_validLanMask;  // not valid
    else
        return "";
}

function checkNetMask(ip1,ip2,ip3,ip4,msg)
{
	var errmsg =  checkInt(ip1,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip2,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip3,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip4,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? addstr(getErrorMsgByVar("gsm_validMask"),msg) : "";
	return errmsg;
}

function checkIpC4(ip1,ip2,ip3,ip4,msg)
{
	var errmsg = "";
	
	if (ip1.value < 1 || ip1.value > 223 || 127 == ip1.value)
	{
		errmsg =  addstr(getErrorMsgByVar("gsm_validIP1"), msg);
		return errmsg;
	}
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip1,msg,1,223,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip2,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip3,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip4,msg,1,254,true);
	errmsg =  (errmsg.length > 1) ? addstr(getErrorMsgByVar("gsm_validIP"),msg) : "";
	return errmsg;
}
function checkSubnetIP(ip1,ip2,ip3,ip4,msg)
{
	if(parseInt(ip1.value,10)==0 && parseInt(ip2.value,10)==0 && parseInt(ip3.value,10)==0 && parseInt(ip4.value,10)==0)
		return "";
	var errmsg =  checkInt(ip1,msg,1,223,true);
	if(ip1.value == "127")
	     errmsg += "ip1 can't be 127";
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip2,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip3,msg,0,255,true);
	errmsg =  (errmsg.length > 1) ? errmsg : checkInt(ip4,msg,0,254,true);
	errmsg =  (errmsg.length > 1) ? msg : "";
	return errmsg;
}
function checkIpMask(ip1,ip2,ip3,ip4,msg)
{
    var errmsg = "";
    if(ip1.value != 255)
    {
        if(ip2.value != 0 || ip3.value != 0 || ip4.value != 0)
        {
            errmsg =  addstr(getErrorMsgByVar("gsm_validMask"), msg);
		        return errmsg;
        }
        switch(parseInt(ip1.value,10))
        {
            case 192:
            case 224:
            case 240:
            case 248:
            case 252:
            case 254:
                break;
            default:
                errmsg =  addstr(getErrorMsgByVar("gsm_validMask1"), msg);
		        return errmsg;
        }
    }
    else if(ip2.value != 255)
    {
        if( ip3.value != 0 || ip4.value != 0)
        {
            errmsg =  addstr(getErrorMsgByVar("gsm_validMask"), msg);
		        return errmsg;
        }
        //0, 128, 192, 224, 240, 248, 252, 254
        switch(parseInt(ip2.value,10))
        {
            case 0:
            case 128:
            case 192:
            case 224:
            case 240:
            case 248:
            case 252:
            case 254:
                break;
            default:
                errmsg =  addstr(getErrorMsgByVar("gsm_validMask2"), msg);
		        return errmsg;
        }
    }
    else if(ip3.value != 255)
    {
        if(ip4.value != 0)
        {
            errmsg =  addstr(getErrorMsgByVar("gsm_validMask"), msg);
		        return errmsg;
        }
        //0, 128, 192, 224, 240, 248, 252, 254
        switch(parseInt(ip3.value,10))
        {
            case 0:
            case 128:
            case 192:
            case 224:
            case 240:
            case 248:
            case 252:
            case 254:
                break;
            default:
                errmsg =  addstr(getErrorMsgByVar("gsm_validMask3"), msg);
		        return errmsg;
        }   
    }
    else
    {
        //0, 128, 192, 224, 240, 248, 252
        switch(parseInt(ip4.value,10))
        {            
            case 0:
            case 128:
            case 192:
            case 224:
            case 240:
            case 248:
            case 252:
                break;
            default:
                errmsg =  addstr(getErrorMsgByVar("gsm_validMask4"), msg);
		        return errmsg;
        }       
    }
    return errmsg;
}

function badIpRange(from1,from2,from3,from4,to1,to2,to3,to4)
// parameters are form fields, returns true if invalid ( from > to )
{
    var total1 = 0;
    var total2 = 0;

    total1 += parseInt(from4.value,10);
    total1 += parseInt(from3.value,10)*256;
    total1 += parseInt(from2.value,10)*256*256;
    total1 += parseInt(from1.value,10)*256*256*256;

    total2 += parseInt(to4.value,10);
    total2 += parseInt(to3.value,10)*256;
    total2 += parseInt(to2.value,10)*256*256;
    total2 += parseInt(to1.value,10)*256*256*256;
    if(total1 > total2)
        return true;
    return false;
}

function badMac(macfld) // macfld is form field, value is changed
{
	var myRE = /[0-9a-fA-F]{12}/;
	var MAC = macfld.value;

	MAC = MAC.replace(/:/g,"");
	MAC = MAC.replace(/-/g,"");
	macfld.value = MAC;

	if((macfld.value.length != 12) || (macfld.value=="000000000000")||(myRE.test(macfld.value)!=true)){
		return true;
	}
	else
	  return false;
}
function badWildcardMac(macfld) // macfld is form field, value is changed
{
	var myRE = /[0-9a-fA-F*]{12}/;
	var MAC = macfld.value;

	MAC = MAC.replace(/:/g,"");
	MAC = MAC.replace(/-/g,"");

	if((macfld.value.length != 17) || (MAC == "************")||(myRE.test(MAC)!=true)){
		return true;
	}
	else
	  return false;
}


function checkMAC(fieldObj,fmsg)
{
	var address = fieldObj.value;

	var myRE = /[0-9a-fA-F]{12}/;
	var newMAC = "";
	if(address.length > 11)
	{
	   newMAC = address.replace(/[:-]/g,"");
	   fieldObj.value = newMAC;	
	}

	if ((newMAC.length != 12) || (newMAC=="000000000000")||(newMAC.charAt(1)%2 != 0)||(myRE.test(newMAC)!=true))	
		return addstr(getErrorMsgByVar("gsm_invalidMAC"),fmsg);	
	else
		return "";
} 

function isBigger(str_a, str_b)
//  true if a bigger than b
{
	var int_value_a = parseInt(str_a);
	var int_value_b = parseInt(str_b);
	return (int_value_a > int_value_b);
}

function isInteger(str,min_value,max_value,allowBlank)  // allowBlank = true or false
// return true if positive Integer, false otherwise
{
	if(str.length == 0)
		if(allowBlank)
			return true;
		else
			return false;
	for (var i=0; i < str.length; i++)
	{
		if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
				return false;
	}
	var int_value = parseInt(str,10);
	if ((int_value < min_value) || (int_value > max_value))
		return false;
	return true;
}


function isHex(str) {
    var i;
    for(i = 0; i<str.length; i++) {
        var c = str.substring(i, i+1);
        if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F")) {
            continue;
        }
        return false;
    }
    return true;
}

function isTelephoneNum(str)
{
	var c;
    if(str.length == 0)
        return false;
    for (var i = 0; i < str.length; i++)
	{
        c = str.substring(i, i+1);
        if (c>= "0" && c <= "9")
            continue;
        if ( c == '-' && i !=0 && i != (str.length-1) )
            continue;
        if ( c == ',' ) continue;
        if (c == ' ') continue;
        if (c>= 'A' && c <= 'Z') continue;
        if (c>= 'a' && c <= 'z') continue;
        return false;
    }
    return true;
}

function checkDay(year,month,day)  // check if valid date
{
	var isleap = false;
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0))
		isleap = true;
	if(month%2)
	{
		if((month<=7)&&(day>31))
			return false;
		if((month>7)&&(day>30))
			return false;
	}
	else
	{
		if(month<=6)
		{
			if(month == 2)
			{
				if((isleap)&&(day>29))
				{
					return false;
				}
				if((!isleap)&&(day>28))
				{
					return false;
				}
			}
			else
			{
				if(day > 30)
					return false;
			}
		}
		else
			if(day>31)
				return false;
	}
	return true;
}

function CheckSpaceInName(text_input_field)
//not allow space in name,
{
	if (text_input_field.value.length>1)
	{
		for (var i=0;i<text_input_field.value.length;i++)
		{
			if (text_input_field.value.charAt(i) == ' ')
				return false;
		}
	}
	return true;
}
//Input Output Ip Address-KelV!n y0u@2004/Oct/24------------------------------------------------------
function IP_T2R(ipbox, ipvar)
{
   var ipstr;
   ipstr= eval("document.forms['main']."+ipbox+"1").value+"."
          +eval("document.forms['main']."+ipbox+"2").value+"."
		  +eval("document.forms['main']."+ipbox+"3").value+"."
		  +eval("document.forms['main']."+ipbox+"4").value;
	eval("document.forms['main']."+ipvar).value = ipstr;
}
function IP_R2T(ipbox, ipvar)
{
	var ipArray = new Array();
	var i;
	var str;

    str = eval("document.forms['main']."+ipvar).value
	if(str.length == 0)
	    return;
	ipArray = str.split(".");
	for(i=1; i<=ipArray.length; i++)
	{
		eval("document.forms['main']."+ipbox+i).value = ipArray[i-1];
	}
}
function IP_STRING_R2T(ipbox, ipstr)
{
	var ipArray = new Array();
	var i;
	var str;

	if(ipstr.length == 0)
	    return;

	ipArray = ipstr.split(".");
	for(i=1; i<=ipArray.length; i++)
	{
		eval("document.forms['main']."+ipbox+i).value = ipArray[i-1];
	}
}
function IP_STRING_T2R(ipbox)
{
   return  eval("document.forms['main']."+ipbox+"1").value+"."
          +eval("document.forms['main']."+ipbox+"2").value+"."
		  +eval("document.forms['main']."+ipbox+"3").value+"."
		  +eval("document.forms['main']."+ipbox+"4").value;
}

// Utility & Misc functions ===================================================
function isIE()
{
    if(navigator.appName.indexOf("Microsoft") != -1)
        return true;
    else return false;
}

function setDisabled(OnOffFlag,formFields)
{
	for (var i = 1; i < setDisabled.arguments.length; i++)
		setDisabled.arguments[i].disabled = OnOffFlag;
}

function makeStr(strSize, fillChar)
{
	var temp = "";
	for (i=0; i < strSize ; i ++)
		temp = temp + fillChar;
	return temp;
}


function getSelIndex(sel_object, sel_text)
{
	if (sel_text.length == 0)
		return -1;   //  Nothing may be valid. e.g. New SAP contain errors & returned.
	var size = sel_object.options.length;
	for (var i = 0; i < size; i++)
	{
		if ( (sel_object.options[i].value == sel_text) || (sel_object.options[i].text == sel_text) )
			return(i);
	}
	if (DEBUG)
 		alert("Selected value " + sel_text + " not found in " + sel_object.name);
	return 0;  // if no match
}


var showit = ""; /* IE: 'block', firefox: 'table-row', but not support chrome */
var hideit = "none";

function show_hide(el,shownow)  // IE & NS6; shownow = true, false
{
//	alert("el = " + el);
	if (document.all)
		document.all(el).style.display = (shownow) ? showit : hideit ;
	else if (document.getElementById)
		document.getElementById(el).style.display = (shownow) ? showit : hideit ;
}

function ValidMacAddress(macAddr)
{
	var i;

	macAddr=macAddr.toUpperCase();

	if ((macAddr.indexOf(':')!=-1)||(macAddr.indexOf('-')!=-1))
	{
        macAddr = macAddr.replace(/:/g,"");
		macAddr = macAddr.replace(/-/g,"");
	}

	if ((macAddr.length == 12) && (macAddr != "000000000000") && (macAddr != "FFFFFFFFFFFF"))
	{
		for(i=0; i<macAddr.length;i++)
		{
			var c = macAddr.substring(i, i+1)
			if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F"))
				continue;
			else
				return false;
		}

		return true;
	}

	return false;
}

function printPage()
{
    location.href="javascript:print();";
}
function checkPwdLength(id, length)
{
    if(length <= id.value.length)
    {
        ;
    }

}

function filter_num(e)
{
    var key = window.event ? e.keyCode:e.which;
    var keychar = String.fromCharCode(key);
    reg = /\d/;

    if(e.ctrlKey)
        return true;

    /* enter, backspace, tab, control on IE / firefox, control on MAC */
    if(13 == key || 8 == key || 9 == key || 0 == key || key > 255)
        return true;

    return reg.test(keychar);
}

function strtohex(str)
{
    var hex_str = "";

    var len = str.length;

    for(i_strtohex = 0; i_strtohex < len; i_strtohex++)
    {
        hex_str += str.charCodeAt(i_strtohex).toString(16);
    }

    return hex_str;
}

var sAscii_hextostr = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"
var sAscii_hextostr = sAscii_hextostr + "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
function hextostr(hex_str)
{
    var len_hextostr = hex_str.length;
    var len_a_hextostr = sAscii_hextostr.length;
    var str = "";

    for(var i_hex_str = 0; i_hex_str < len_hextostr; i_hex_str = i_hex_str+2)
    {
        var index = parseInt(hex_str.substring(i_hex_str, i_hex_str +2), 16);

        if(index < 32 || index >= 32 + len_a_hextostr)
            break;

        if('"' == sAscii_hextostr.charAt(index - 32))
            str += '&quot;';
        else
            str += sAscii_hextostr.charAt(index - 32);
    }

    return str;
}

function filter_enter(e)
{
    var key = window.event ? e.keyCode : e.which;

    if(13 == key)
        return true;
    else
    	return false;
}

function getDisplay(el)  // IE & NS6; shownow = true, false
{
	if (document.all)
		return (document.all(el).style.display == showit);
	else if (document.getElementById)
		return (document.getElementById(el).style.display == showit);
}

//This function will close help file of current page.
function close_help()
{
    if(top.help_todo_self)
        top.help_todo_self(0);
}

//This function will close help file of current page.pls ignore it's function name because it's history 
function open_help()
{
    if(top.help_todo_self)
        top.help_todo_self(0);
}
//This function will set help file of current page show or hide.
function HH()
{
	/*
    if(top.help_todo_self)
        top.help_todo_self(1);
	*/
	var this_file = document.forms["main"].this_file.value;
    var nfile_name = '/help-en/h_' + this_file;
    helpWinVar = window.open(nfile_name,'help_win',HelpOptionsVar);
	if (helpWinVar.focus)
		setTimeout('helpWinVar.focus()',200);
}

function CH()
{
    if(top.frames.length != 0)
    {
        if(this.frames.name == "helpframe")
        {
            if(top.help_todo_self)
                top.help_todo_self(0);
    	}
    	else if(this.frames.name == "main")
    	    this.frames.location.href = "help.htm";
	}
	else
	    self.close();
}

function disableAll(flag, form_obj)
{
	if(flag == '1')
	{
		var form_size = form_obj.elements.length;
		for (var i = 0; i < form_size; i++)
		{
		  if(form_obj.elements[i].name != "cancel")
			    form_obj.elements[i].disabled = true;
		}
	}
}

function reload_menu(menulist)
{
    var menu;
	if(parent.frames.length >= 2)
	{
	    if(parent.frames[1].document.getElementById('menu_list'))
		    menu = parent.frames[1].document.getElementById('menu_list').value;
		if(menulist)
	    {
    		if(menu != menulist)
    		{
    			parent.frames[1].location = "menu.htm";
    		}
	    }
	}
}


function chkSelected(selObj, err_msg)
{
    if(!(selObj.selectedIndex >= 0 ))
	{
	    alert(err_msg);
	    return false;
	}
	return true;
}

function getRadioCheckedValue(radio_object)
{
	var size = radio_object.length;
	for (var i = 0; i < size; i++)
	{
		if (radio_object[i].checked == true)
			return(radio_object[i].value)
	}
	return (radio_object[0].value); // first value if nothing checked
}

function getRadioIndex(radio_object, checked_value)  
{
	var size = radio_object.length;
	for (var i = 0; i < size; i++)
	{
		if (radio_object[i].value == checked_value)
			return  i;
	}

	return  0;   // if no match
}


function addstr(input_msg)
{
	var last_msg = "";
	var str_location;
	var temp_str_1 = "";
	var temp_str_2 = "";
	var str_num = 0;
	temp_str_1 = addstr.arguments[0];
	while(1)
	{
		str_location = temp_str_1.indexOf("%s");
		if(str_location >= 0)
		{
			str_num++;
			temp_str_2 = temp_str_1.substring(0,str_location);
			last_msg += temp_str_2 + addstr.arguments[str_num];
			temp_str_1 = temp_str_1.substring(str_location+2,temp_str_1.length);
			continue;
		}
		if(str_location < 0)
		{
			last_msg += temp_str_1;
			break;
		}
	}
	return last_msg;
}

function isIPaddr(addr) {
    var i;     var a; 
    a = addr.split(".");
    if(a.length != 4) {
        return false;
    }
    for(i = 0; i < a.length; i++) 
		if (!(isInt(a[i], (i==0||i==3)?1:0, (i==0||i==3)?254:255)))
			return false;
    return true;
}

function isInt(str, min_value, max_value)
{
	if (str.length==0) // blank
			return false
	for (var i=0; i < str.length; i++)
		if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
			return false;
	var int_value = parseInt(str,10);
	if ((int_value < min_value) || (int_value > max_value))
		return false;
	return true;
}
/* MD@CPU_AP add for smtp */
function checkMail(fobj, fname)
{
   var tmp_str = fobj.value;
   var msg = "";

   //matching Email address format(regular expression)
   var pattern = /^([a-zA-Z0-9]+[_|\-|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\-|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/gi;

   if(!pattern.test(tmp_str))
     msg = addstr(getErrorMsgByVar("gsm_invalid_email"), fname);

   return msg;
}
/* add end */

function isHex(str)
{
   for(i=0; i < str.length; i++)
  {
 	 if (isNaN(parseInt(str.charAt(i), 16)))
	 	return false;
  }
  return true;
}

function setDisable(dflag,objects)  // objects can be individual, or an array of objects
{
	for (var i=1; i < setDisable.arguments.length; i++)
	{
		if(setDisable.arguments[i].type == undefined && setDisable.arguments[i].length) // array
			for(var j = 0; j < setDisable.arguments[i].length; j++)
				setDisable.arguments[i][j].disabled = dflag;
		else
			setDisable.arguments[i].disabled = dflag;
	}
}

function setOptions(selObj, optionList) // rebuild option list from parameters
{
	var oldValue =  selObj.options[selObj.selectedIndex].text ;
	selObj.options.length = 0;
	for (var i = 1; i < setOptions.arguments.length; i++)
	{
		selObj.options[selObj.options.length] = new Option(arguments[i],arguments[i]);		
	}
	selObj.selectedIndex =  getSelIndex(selObj, oldValue)
}

function setOptionsWithValue(selObj, optionList) // rebuild option list from parameters
{
	var oldValue =  selObj.options[selObj.selectedIndex].text;
	selObj.options.length = 0;
	for (var i = 1; i < setOptionsWithValue.arguments.length; i += 2)
	{
		selObj.options[selObj.options.length] = new Option(arguments[i],arguments[i+1]);		
	}
	selObj.selectedIndex =  getSelIndex(selObj, oldValue)
}


function IsNameChar(NameString)
{
	/* valid chars: letters, numbers, underline, and - . [ ] ( ) @ / ~ # * \ $ | */
    var pattern = /^[\w- \.\[\]\(\)\@\/\~\#\*\$\|\+]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;

}

function IsNameCharForSSID(NameString)//It has wider range than IsNameChar
{
    var pattern = /^[\w- \`\~\!\$\%\^\&\*(\)\_\-\+\=\|\\\{\}\[\]\:\"\;\'\,\.\<\>\/\?]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;

}

function IsDomainChar(NameString)
{
	/* valid chars: letters, numbers, underline, - . */
    var pattern = /^[\w-\.]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;
}
function IsHostnameChar(NameString)
{
	/* valid chars: letters, numbers, underline, - . */
    var pattern = /^[a-zA-Z0-9]+[\w-]+[a-zA-Z0-9]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;
}
function IsNetBiosNameChar(NameString)
{
	/* can not include \ / : * ? " < > | */
    var pattern = /^[\w-\.\(\)\[\]@\~\#\$\`\+\^\!\{\}]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;
}
function IsHTMLSafeChar(NameString)
{
	/* valid chars: letters, numbers, underline, space, and - . ( ) @ : / ~ # * $ | ` + ^ ! { } ? */
    var pattern = /^[\w \-\.\(\)\[\]@\:\/\~\#\*\$\|\`\+\^\!\{\}\?]+$/;
    if(!pattern.test(NameString))
          return false;
    return true;
}

function checkNetBiosNameChar(fobj, fname, required)
{
	if(fobj.value.length < 1)
	{
		if(!required)
			return "";
		else
			return  addstr(getErrorMsgByVar("gsm_blank"),fname);
	}
	if(!IsNameChar(fobj))
		return addstr(getErrorMsgByVar("msg_invalid_netBiosNamechar"), fname);
	else
		return "";
}

function checkNameChar(fobj, fname, required)
{
	if(fobj.value.length < 1)
	{
		if(!required)
			return "";
		else
			return addstr(getErrorMsgByVar("gsm_blank"),fname);
	}
	if(!IsNameChar(fobj))
		return addstr(getErrorMsgByVar("msg_invalid_namechar"), fname);
	else
		return "";
}

function checkHostNameChar(fobj, fname, required)
{
	if (fobj.value.length < 1)
	{
		if(! required)
			return "";
		else
			return  addstr(getErrorMsgByVar("gsm_blank"),fname);
	}
	if(!IsHostnameChar(fobj))
		return addstr(getErrorMsgByVar("msg_invalid_netHostNamechar"), fname);
	else return "";
}

function checkDomainChar(fobj, fname, required)
{
	if (fobj.value.length < 1)
	{
		if(! required)
			return "";
		else
			return  addstr(getErrorMsgByVar("gsm_blank"),fname);
	}
	if(! IsDomainChar(fobj))
		return addstr(getErrorMsgByVar("msg_invalid_domainchar"), fname);
	else
		return "";
}

function checkHTMLSafeChar(fobj, fname, required)
{
	if (fobj.value.length < 1)
	{
		if(! required)
			return "";
		else
			return  addstr(getErrorMsgByVar("gsm_blank"),fname);
	}
	if(! IsHTMLSafeChar(fobj))
		return addstr(getErrorMsgByVar("msg_invalid_htmlsafechar"), fname);
	else 
		return "";
}

function isNumber(object,field_name)
{
    var str = object.value;
    var error_msg="";
    for (var i=0; i < str.length; i++)
	{
		if((i == 0) && (str.charAt(i) == '-'))
		{
			continue;
		}
		else if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
			error_msg = addstr(getErrorMsgByVar("gsm_check_invalid"), field_name);
	}
	if(error_msg.length > 2){
	    return error_msg;
	}
	return error_msg;
}

function isTelephoneNumber(object,field_name)
{
    var str = object.value;
    var error_msg="";
    for (var i=0; i < str.length; i++)
	{
		if((i == 0) && ((str.charAt(i) == '-') || (str.charAt(i) == '+')))
		{
			continue;
		}
		else if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
			error_msg = addstr(getErrorMsgByVar("gsm_check_invalid"), field_name);
	}
	if(error_msg.length > 2){
	    return error_msg;
	}
	return error_msg;
}

function checkVoIPToneInt(text_input_field, field_name, min_value, max_value, required)
{
	var str = text_input_field.value;
	var error_msg= "";

	if (text_input_field.value.length == 0) // blank
	{
		return(error_msg);
	}
	else
	{
		for(var i = 0; i < str.length; i++)
		{
			if((i == 0) && (str.charAt(i) == '-'))
			{
				continue;
			}
			else if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
			{
				error_msg = addstr(getErrorMsgByVar("gsm_check_invalid"),field_name);
			}
		}
		if (error_msg.length < 2)
		{
			var int_value = parseInt(str,10);
			if (int_value < min_value)
				error_msg = addstr(getErrorMsgByVar("gsm_greater"),field_name,(min_value - 1));
			if (int_value > max_value)
				error_msg = addstr(getErrorMsgByVar("gsm_less"),field_name,(max_value + 1));
		}
	}
	return(error_msg);
}
function chkIP_HostName_DnsName(fobj, msg)
{
	if(fobj.value.length == 0)
		return msg;
	
	var a = fobj.value.split(".");
		
	if ((a.length == 4) && isIPaddr(fobj.value))
		return "";
	if((a.length >= 2) && (IsDomainChar(fobj.value)))
		return "";
	if (IsHostnameChar(fobj.value) && (!checkAllNumChars(fobj.value)))
		return "";

    if (checkAllNumChars(fobj.value)){
         return (msg + getErrorMsgByVar("gsm_not_number"));
	}      	
	else return msg;
}

function chkIP_HostName(fobj, msg) // input could be ip or name
{
	if(fobj.value.length == 0)
		return msg;
		
	var a = fobj.value.split(".");
	
	if((a.length == 4) && (!(isIPaddr(fobj.value))))
		return msg;
	if(isIPaddr(fobj.value))
		return "";
	if(IsHostnameChar(fobj.value)&& (!checkAllNumChars(fobj.value)))
		return "";
	if(checkAllNumChars(fobj.value))
	{
         return (msg + getErrorMsgByVar("gsm_not_number"));
    }
	else return msg;
}

function chkIP_DnsName(fobj, msg) // input could be ip or dns
{
	if(fobj.value.length == 0)
		return msg;
	
	var a = fobj.value.split(".");
	
	if(a.length == 4)
	{ 
	    if(isIPaddr(fobj.value))
		    return "";
	    else
	    {
	        for(var i=0; i < fobj.value.length; i++)
		        if(((fobj.value.charAt(i) < '0') || (fobj.value.charAt(i) > '9')) && (fobj.value.charAt(i) != '.'))
		            break;
	        if(i == fobj.value.length)        
	            return msg;        
	    }
	}		
	if((a.length >= 2) && (IsDomainChar(fobj.value)))
		return "";
	else 
		return msg;
}
function chkDnsName(fobj, msg) // input could be ip or dns
{
	if(fobj.value.length == 0)
		return msg;
		
	var a = fobj.value.split(".");
	
	if((a.length >= 2) && (IsDomainChar(fobj.value)))
		return "";
	else 
		return msg;
}

function chkHostName(fobj, msg) // input could be ip or dns
{
	if(fobj.value.length == 0)
		return msg;

	if(IsHostnameChar(fobj.value) && (!checkAllNumChars(fobj.value)))
		return "";
	if(checkAllNumChars(fobj.value))
	{
         return (msg + getErrorMsgByVar("gsm_not_number"));
    }
    return msg;
}

function chkGeneralName(fobj, msg) // input could be name
{
    if(IsNameChar(fobj.value))
		return "";
    return msg;
}

function checkPassword(oldp, newp, confirmp)
{
   	var msg = "";
    msg += checkHTMLSafeChar(oldp, "Old Password", false);
    msg += checkHTMLSafeChar(newp, "New Password", false);
	if(msg.length > 1)
	{
		alert(msg);
		return false;
	}

	if(newp.value != confirmp.value)
	{
		alert(msg_password_match);
		return false;
	}
	if(newp.value=="")
	{
		if(confirm(msg_password_empty))
          return true;
        else
          return false;
	}

	return true;	
}

function show_hide_html()
{	
	var div_sub = document.getElementsByTagName("div");
    var i;

	for(i = 0; i < div_sub.length; i++)
	{
		if(div_sub[i].id.length != 0)
		{
			if(div_sub[i].getAttribute("name") < user_level)
			{							
				document.getElementById(div_sub[i].id).style.display = "none";
			}
		}
	}
}
function gid(id)
{
	return document.getElementById(id);
}
function init_pwdfield(passwordbox)
{
	/* create new textbox element like html code if passwordbox is a input
	 * element like
	 * <input id="pppoePasswd" type="password" class="pwdstyle" value="*******">,
	 * then we created textbox element like
	 * <input id="_pppoePasswd" type="text" style="display:none" class="pwdstyle">
	 */
	var textbox = document.createElement("input");
	textbox.type = "text";
	textbox.id = "_" + passwordbox.id;
	textbox.style.display="none";
	textbox.size = passwordbox.size;
	textbox.maxLength = passwordbox.maxLength;
	/* textbox is not as width as passwordbox in IE brower at the same size.
	 * <input type="password" value="1234" size="15">
	 * <input type="text" value="1234" size="15">
	 * so we need set style="width:120px" or set class="password" attribute for
	 * the passwordbox.
	 */
	textbox.className = passwordbox.className;
	textbox.style.width = passwordbox.style.width; /* for IE brower */
	if(passwordbox.value != input_hidden)
	{
        textbox.value = passwordbox.value;
        textbox.defaultValue = passwordbox.defaultValue;
    }

	/* initializes the textbox element onkeyup event handle.*/
	/*
	textbox.onkeyup = function(){
		if(textbox.value != textbox.defaultValue)
		{
			passwordbox.ischange = true;
		}
		if(passwordbox.ischange)
		{
			passwordbox.value=this.value;
		}
	};
	*/
	/* initializes the textbox element onblur event handle.*/
	textbox.onblur = function(){
	    if(textbox.value != textbox.defaultValue)
		{
			passwordbox.ischange = true;
		}
		if(passwordbox.ischange)
		{
			passwordbox.value=this.value;
		}
		passwordbox.style.display="";
		textbox.style.display="none";
	};
	/* initializes the textbox element finished. */

	/* initializes the passwordbox element onfocus event handle.*/
	passwordbox.onfocus = function(){
		/* when passwordbox get focus we hide the passwordbox and show the textbox. */
		passwordbox.style.display="none";
		textbox.style.display="";
		//textbox.value = passwordbox.value;
		textbox.focus();
	};
	/* insert the textbox element before the passwordbox element.*/
	passwordbox.parentNode.insertBefore(textbox,passwordbox);
}
function help_link()
{
    dw('<a class="more" href="javascript:void(0);" onClick="HH()" languageCode="More_info">');
    dw('More Info');
    dw('</a>');
}
function allpy_btn(func)
{
    dw('<input type="submit" name="save" value="');
    dw('Apply');
    dw('" onClick="return ');
    dw(func);
    dw('();" languageCode="Apply">');
}
function next_btn(func)
{
    dw('<input type="submit" name="save" value="');
    dw('Next');
    dw('" onClick="return ');
    dw(func);
    dw('();" languageCode="Next">');
}
function cancel_btn(pageName)
{
    dw('<input type="RESET" name="Cancel" value="');
    dw('Cancel');
    dw('" onClick="location.href=\'setup.cgi?next_file=');
    dw(pageName);
    dw('\'; return true;" languageCode="Cancel">');
}
function close_btn()
{
	dw('<input type="button" name="close" value="');
	dw('Close');
	dw('" onClick="CH()" languageCode="Close">');
}
function save_btn(func)
{
    dw('<input type="submit" name="save" value="');
    dw('Save');
    dw('" onClick="return ');
    dw(func);
    dw('();" languageCode="Save">');
}


function disable_fields(theForm) 
{
  var len = theForm.elements.length;
  for (var i = 0; i < len; i++) {
    // Don't disable "hidden" fields
    if(theForm.elements[i].type.toLowerCase()!="hidden")
      theForm.elements[i].disabled = 1;
  }
}

function submitForm(theForm, customP)
{
    if (customP)
        theForm.action += "&" + customP;
    theForm.submit();
    disable_fields(theForm);
}
function atoc(str, num)
{
        i = 1;
        if (num != 1) {
                while (i != num && str.length != 0) {
                        if (str.charAt(0) == '.') {
                                i++;
                        }
                        str = str.substring(1);
                }
                if (i != num)
                        return -1;
        }

        for (i=0; i<str.length; i++) {
                if (str.charAt(i) == '.') {
                        str = str.substring(0, i);
                        break;
                }
        }
        if (str.length == 0)
                return -1;
        return str;
}
function atoi(str, num)
{
	i = 1;
	if (num != 1) {
		while (i != num && str.length != 0) {
			if (str.charAt(0) == '.') {
				i++;
			}
			str = str.substring(1);
		}
		if (i != num)
			return -1;
	}

	for (i=0; i<str.length; i++) {
		if (str.charAt(i) == '.') {
			str = str.substring(0, i);
			break;
		}
	}
	if (str.length == 0)
		return -1;
	return parseInt(str, 10);
}
function isAllNum(str)
{
	for (var i=0; i<str.length; i++) {
		if ((str.charAt(i) >= '0' && str.charAt(i) <= '9') || (str.charAt(i) == '.' ))
			continue;
		return 0;
	}
	return 1;
}
function checkRange(str, num, min, max)
{
	d = atoi(str, num);
	if (d > max || d < min)
		return false;
	return true;
}
function checkNumformat(str)
{
	if (str.length > 1 && str.charAt(0) == '0')
                return 0;
	return 1;
}
