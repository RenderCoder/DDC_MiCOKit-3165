/**
******************************************************************************
* @file    http-string.c 
* @author  QQ DING
* @version V1.0.0
* @date    1-September-2015
* @brief   String associated with HTTP
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/

#include "mico.h"

const char http_http[8] =
/* "http://" */
{ 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, };
const char http_200[5] =
/* "200 " */
{ 0x32, 0x30, 0x30, 0x20, };
const char http_301[5] =
/* "301 " */
{ 0x33, 0x30, 0x31, 0x20, };
const char http_302[5] =
/* "302 " */
{ 0x33, 0x30, 0x32, 0x20, };
const char http_get[5] =
/* "GET " */
{ 0x47, 0x45, 0x54, 0x20, };
const char http_post[6] =
/* "POST " */
{ 0x50, 0x4f, 0x53, 0x54, 0x20, };
const char http_put[5] =
/* "PUT " */
{0x50, 0x55, 0x54, 0x20, };
const char http_delete[8] =
/* "DELETE " */
{0x44, 0x45, 0x4c, 0x45, 0x54, 0x45, 0x20, };
const char http_head[6] =
/* "HEAD " */
{0x48, 0x45, 0x41, 0x44, 0x20, };
const char http_10[9] =
/* "HTTP/1.0" */
{ 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30, };
const char http_11[9] =
/* "HTTP/1.1" */
{ 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31, };
const char http_last_chunk[6] =
/* "0\r\n\r\n" */
{ 0x30, 0xd, 0xa, 0xd, 0xa, };
const char http_content_type[15] =
/* "Content-Type: " */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, };
const char http_content_len[17] =
/* "Content-Length: " */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x4c, 0x65, 0x6e, 0x67, 0x74,
	    0x68, 0x3a, 0x20, };
const char http_encoding[20] =
/* "Transfer-Encoding: " */
{ 0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x65, 0x72, 0x2d, 0x45, 0x6e, 0x63, 0x6f,
	    0x64, 0x69, 0x6e, 0x67, 0x3a, 0x20, };
const char http_texthtml[10] =
/* "text/html" */
{ 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, };
const char http_location[11] =
/* "location: " */
{ 0x6c, 0x6f, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, };
const char http_host[7] =
/* "host: " */
{ 0x68, 0x6f, 0x73, 0x74, 0x3a, 0x20, };
const char http_crnl[3] =
/* "\r\n" */
{ 0xd, 0xa, };
const char http_index_html[12] =
/* "/index.html" */
{ 0x2f, 0x69, 0x6e, 0x64, 0x65, 0x78, 0x2e, 0x68, 0x74, 0x6d, 0x6c, };
const char http_404_html[10] =
/* "/404.html" */
{ 0x2f, 0x34, 0x30, 0x34, 0x2e, 0x68, 0x74, 0x6d, 0x6c, };
const char http_referer[9] =
/* "Referer:" */
{ 0x52, 0x65, 0x66, 0x65, 0x72, 0x65, 0x72, 0x3a, };

const char http_header_server[] = "Server: MXCHIP\r\n";
const char http_header_conn_close[] = "Connection: close\r\n";
const char http_header_conn_keep_alive[] = "Connection: keep-alive\r\n";
const char http_header_keep_alive_ctrl[] = "Keep-Alive: timeout=5, max=100\r\n";
const char http_header_type_chunked[] = "Transfer-Encoding: chunked\r\n";
const char http_header_cache_ctrl[] =
	"Cache-Control: no-store, no-cache, must-revalidate\r\n";
const char http_header_cache_ctrl_no_chk[] =
	"Cache-Control: post-check=0, pre-check=0\r\n";
const char http_header_pragma_no_cache[] = "Pragma: no-cache\r\n";
const char httpd_authrized[] = {
"HTTP/1.1 401 Authorization Required\r\n"
"Server: MySocket Server\r\n"
"WWW-Authenticate: Basic realm=\""MODEL"\"\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 169\r\n\r\n"
"<HTML>\r\n<HEAD>\r\n<TITLE>Error</TITLE>\r\n"
"<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=ISO-8859-1\">\r\n"
"</HEAD>\r\n<BODY><H1>401 Unauthorized.</H1></BODY>\r\n</HTML>"
};

const char http_header_200_keepalive[66] =
/* "HTTP/1.1 200 OK\r\nServer: Marvell-WM\r\nTransfer-Encoding: chunked\r\n"
 * */
{ 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31, 0x20, 0x32, 0x30, 0x30, 0x20,
	    0x4f, 0x4b, 0xd, 0xa, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x3a,
	    0x20, 0x4d, 0x61, 0x72, 0x76, 0x65, 0x6c, 0x6c, 0x2d, 0x57, 0x4d,
	    0xd, 0xa, 0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x65, 0x72, 0x2d,
	    0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x3a, 0x20, 0x63,
	    0x68, 0x75, 0x6e, 0x6b, 0x65, 0x64, 0xd, 0xa, };

const char http_header_200[] = "HTTP/1.1 200 OK\r\n";

const char http_header_304_prologue[] = "HTTP/1.1 304 Not Modified\r\n";
const char http_header_404[] = "HTTP/1.1 404 Not Found\r\n";
const char http_header_400[] = "HTTP/1.1 400 Bad Request\r\n";
const char http_header_500[] = "HTTP/1.1 500 Internal Server Error\r\n";
const char http_header_505[] = "HTTP/1.1 505 HTTP Version Not Supported\r\n";

const char http_content_type_plain[27] =
/* "Content-Type: text/plain\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x70, 0x6c, 0x61, 0x69, 0x6e,
	    0xd, 0xa, };
const char http_content_type_html[26] =
/* "Content-Type: text/html\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c,
	    0xd, 0xa, };
const char http_content_type_charset_html[45] =
/* "Content-Type: text/html; charset=iso8859-1\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, 0x3b,
	    0x20, 0x63, 0x68, 0x61, 0x72, 0x73, 0x65, 0x74, 0x3d, 0x69, 0x73,
	    0x6f, 0x38, 0x38, 0x35, 0x39, 0x2d, 0x31, 0xd, 0xa, };
const char http_content_type_html_nocache[157] =
/* "Content-Type: text/html; charset=iso8859-1\r\nCache-Control: no-store,
 * no-cache, must-revalidate\r\nCache-Control: post-check=0, pre-check=0\r\n
 * Pragma: no-cache\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, 0x3b,
	    0x20, 0x63, 0x68, 0x61, 0x72, 0x73, 0x65, 0x74, 0x3d, 0x69, 0x73,
	    0x6f, 0x38, 0x38, 0x35, 0x39, 0x2d, 0x31, 0xd, 0xa, 0x43, 0x61,
	    0x63, 0x68, 0x65, 0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c,
	    0x3a, 0x20, 0x6e, 0x6f, 0x2d, 0x73, 0x74, 0x6f, 0x72, 0x65, 0x2c,
	    0x20, 0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65, 0x2c, 0x20,
	    0x6d, 0x75, 0x73, 0x74, 0x2d, 0x72, 0x65, 0x76, 0x61, 0x6c, 0x69,
	    0x64, 0x61, 0x74, 0x65, 0xd, 0xa, 0x43, 0x61, 0x63, 0x68, 0x65,
	    0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x3a, 0x20, 0x70,
	    0x6f, 0x73, 0x74, 0x2d, 0x63, 0x68, 0x65, 0x63, 0x6b, 0x3d, 0x30,
	    0x2c, 0x20, 0x70, 0x72, 0x65, 0x2d, 0x63, 0x68, 0x65, 0x63, 0x6b,
	    0x3d, 0x30, 0xd, 0xa, 0x50, 0x72, 0x61, 0x67, 0x6d, 0x61, 0x3a,
	    0x20, 0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65, 0xd, 0xa, };
const char http_content_type_css[25] =
/* "Content-Type: text/css\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x63, 0x73, 0x73, 0xd, 0xa, };
const char http_content_type_text[28] =
/* "Content-Type: text/text\r\n\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x74, 0x65, 0x78, 0x74, 0xd,
	    0xa, 0xd, 0xa, };
const char http_content_type_png[26] =
/* "Content-Type: image/png\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x70, 0x6e, 0x67, 0xd,
	    0xa, };
const char http_content_type_gif[26] =
/* "Content-Type: image/gif\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x67, 0x69, 0x66, 0xd,
	    0xa, };
const char http_content_type_jpg[27] =
/* "Content-Type: image/jpeg\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x6a, 0x70, 0x65, 0x67,
	    0xd, 0xa, };
const char http_content_type_js[32] =
/* "Content-Type: text/javascript\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x6a, 0x61, 0x76, 0x61, 0x73,
	    0x63, 0x72, 0x69, 0x70, 0x74, 0xd, 0xa, };
const char http_content_type_binary[41] =
/* "Content-Type: application/octet-stream\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x6f, 0x63, 0x74, 0x65, 0x74, 0x2d, 0x73, 0x74, 0x72,
	    0x65, 0x61, 0x6d, 0xd, 0xa, };
const char http_content_type_binary_nocrlf[41] =
/* "Content-Type: application/octet-stream\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x6f, 0x63, 0x74, 0x65, 0x74, 0x2d, 0x73, 0x74, 0x72,
	    0x65, 0x61, 0x6d, 0xd, 0xa, };
const char http_content_type_json[35] =
/* "Content-Type: application/json\r\n\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x6a, 0x73, 0x6f, 0x6e, 0xd, 0xa, 0xd, 0xa, };
const char http_content_type_json_nocrlf[33] =
/* "Content-Type: application/json\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x6a, 0x73, 0x6f, 0x6e, 0xd, 0xa, };
const char http_content_type_json_nocache[147] =
/* "Content-Type: application/json\r\nCache-Control: no-store, no-cache,
 * must-revalidate\r\nCache-Control: post-check=0, pre-check=0\r\nPragma:
 * no-cache\r\n\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x6a, 0x73, 0x6f, 0x6e, 0xd, 0xa, 0x43, 0x61, 0x63,
	    0x68, 0x65, 0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x3a,
	    0x20, 0x6e, 0x6f, 0x2d, 0x73, 0x74, 0x6f, 0x72, 0x65, 0x2c, 0x20,
	    0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65, 0x2c, 0x20, 0x6d,
	    0x75, 0x73, 0x74, 0x2d, 0x72, 0x65, 0x76, 0x61, 0x6c, 0x69, 0x64,
	    0x61, 0x74, 0x65, 0xd, 0xa, 0x43, 0x61, 0x63, 0x68, 0x65, 0x2d,
	    0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x3a, 0x20, 0x70, 0x6f,
	    0x73, 0x74, 0x2d, 0x63, 0x68, 0x65, 0x63, 0x6b, 0x3d, 0x30, 0x2c,
	    0x20, 0x70, 0x72, 0x65, 0x2d, 0x63, 0x68, 0x65, 0x63, 0x6b, 0x3d,
	    0x30, 0xd, 0xa, 0x50, 0x72, 0x61, 0x67, 0x6d, 0x61, 0x3a, 0x20,
	    0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65, 0xd, 0xa, 0xd, 0xa,
	};
const char http_content_type_xml_nocache[139] =
/* "Content-Type: text/xml\r\nCache-Control: no-store, no-cache,
 * must-revalidate\r\nCache-Control: post-check=0, pre-check=0\r\nPragma:
 * no-cache\r\n\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x78, 0x6d, 0x6c, 0xd, 0xa,
	    0x43, 0x61, 0x63, 0x68, 0x65, 0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72,
	    0x6f, 0x6c, 0x3a, 0x20, 0x6e, 0x6f, 0x2d, 0x73, 0x74, 0x6f, 0x72,
	    0x65, 0x2c, 0x20, 0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65,
	    0x2c, 0x20, 0x6d, 0x75, 0x73, 0x74, 0x2d, 0x72, 0x65, 0x76, 0x61,
	    0x6c, 0x69, 0x64, 0x61, 0x74, 0x65, 0xd, 0xa, 0x43, 0x61, 0x63,
	    0x68, 0x65, 0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x3a,
	    0x20, 0x70, 0x6f, 0x73, 0x74, 0x2d, 0x63, 0x68, 0x65, 0x63, 0x6b,
	    0x3d, 0x30, 0x2c, 0x20, 0x70, 0x72, 0x65, 0x2d, 0x63, 0x68, 0x65,
	    0x63, 0x6b, 0x3d, 0x30, 0xd, 0xa, 0x50, 0x72, 0x61, 0x67, 0x6d,
	    0x61, 0x3a, 0x20, 0x6e, 0x6f, 0x2d, 0x63, 0x61, 0x63, 0x68, 0x65,
	    0xd, 0xa, 0xd, 0xa, };
const char http_content_type_form[52] =
/* "Content-Type: application/x-www-form-urlencoded\r\n\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x78, 0x2d, 0x77, 0x77, 0x77, 0x2d, 0x66, 0x6f, 0x72,
	    0x6d, 0x2d, 0x75, 0x72, 0x6c, 0x65, 0x6e, 0x63, 0x6f, 0x64, 0x65,
	    0x64, 0xd, 0xa, 0xd, 0xa, };
const char http_content_type_form_nocrlf[50] =
/* "Content-Type: application/x-www-form-urlencoded\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65, 0x3a,
	    0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
	    0x6e, 0x2f, 0x78, 0x2d, 0x77, 0x77, 0x77, 0x2d, 0x66, 0x6f, 0x72,
	    0x6d, 0x2d, 0x75, 0x72, 0x6c, 0x65, 0x6e, 0x63, 0x6f, 0x64, 0x65,
	    0x64, 0xd, 0xa, };
const char http_content_type_text_cache_manifest[36] =
/* "Content-Type: text/cache-manifest\r\n" */
{ 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x54, 0x79, 0x70, 0x65,
0x3a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x63, 0x61, 0x63, 0x68, 0x65, 0x2d,
0x6d, 0x61, 0x6e, 0x69, 0x66, 0x65, 0x73, 0x74, 0xd, 0xa, };
const char http_content_encoding_gz[48] =
/* "Vary: Accept-Encoding\r\nContent-Encoding: gzip\r\n" */
{ 0x56, 0x61, 0x72, 0x79, 0x3a, 0x20, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d,
	    0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0xd, 0xa, 0x43,
	    0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x45, 0x6e, 0x63, 0x6f,
	    0x64, 0x69, 0x6e, 0x67, 0x3a, 0x20, 0x67, 0x7a, 0x69, 0x70, 0xd,
	    0xa, };
const char http_html[6] =
/* ".html" */
{ 0x2e, 0x68, 0x74, 0x6d, 0x6c, };
const char http_shtml[7] =
/* ".shtml" */
{ 0x2e, 0x73, 0x68, 0x74, 0x6d, 0x6c, };
const char http_htm[5] =
/* ".htm" */
{ 0x2e, 0x68, 0x74, 0x6d, };
const char http_css[5] =
/* ".css" */
{ 0x2e, 0x63, 0x73, 0x73, };
const char http_png[5] =
/* ".png" */
{ 0x2e, 0x70, 0x6e, 0x67, };
const char http_gif[5] =
/* ".gif" */
{ 0x2e, 0x67, 0x69, 0x66, };
const char http_jpg[5] =
/* ".jpg" */
{ 0x2e, 0x6a, 0x70, 0x67, };
const char http_text[5] =
/* ".txt" */
{ 0x2e, 0x74, 0x78, 0x74, };
const char http_txt[5] =
/* ".txt" */
{ 0x2e, 0x74, 0x78, 0x74, };
const char http_xml[5] =
/* ".xml" */
{ 0x2e, 0x78, 0x6d, 0x6c, };
const char http_js[4] =
/* ".js" */
{ 0x2e, 0x6a, 0x73, };
const char http_gz[4] =
/* ".gz" */
{ 0x2e, 0x67, 0x7a, };
const char http_manifest[10] =
/* ".manifest" */
{ 0x2e, 0x6d, 0x61, 0x6e, 0x69, 0x66, 0x65, 0x73, 0x74, };
const char http_user_agent[11] =
/* "User-Agent" */
{ 0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65, 0x6e, 0x74, };
const char http_if_modified_since[18] =
/* "If-Modified-Since" */
{ 0x49, 0x66, 0x2d, 0x4d, 0x6f, 0x64, 0x69, 0x66, 0x69, 0x65, 0x64, 0x2d,
0x53, 0x69, 0x6e, 0x63, 0x65, };
const char http_cache_control[28] =
/* "Cache-Control: max-age=10\r\n" */
{ 0x43, 0x61, 0x63, 0x68, 0x65, 0x2d, 0x43, 0x6f, 0x6e, 0x74, 0x72,
0x6f, 0x6c, 0x3a, 0x20, 0x6d, 0x61, 0x78, 0x2d, 0x61, 0x67, 0x65,
0x3d, 0x31, 0x30, 0xd, 0xa, };
