#ifndef OnShape_h
#define OnShape_h

#include "Arduino.h"

#include <SPI.h>
#include <WiFiNINA.h>
#include <TimeLib.h>

#include <sha256.h>

class OnShape
{
	public:
		OnShape(String accessKey, const char secretKey[]);
		void start(const char ssid[], const char pass[]);

		/* Wrapper functions */
		String getDocument(String documentID);
    String newDocument(char doc_name[]);
    String transformMate(char  angle[]) ;
    String assemblyData() ;


		/* Raw request functions (use these if no wrapper function exists) */
		String makeRequest(String reqType, String path);
		String makeRequest(String reqType, String path, const char data[]);
	private:
		String _accessKey;
		const char *_secretKey;
		WiFiSSLClient _client;

		void connectWifi(const char ssid[], const char pass[]);
		void printWifiStatus();

		String buildNonce();
		String utcString();
		String getHmac64(String payload, String key);
		String buildHeaders(String method, String urlpath, String nonce, String date, String contentType, String urlquery);
		
};

#endif
