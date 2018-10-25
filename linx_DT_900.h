#ifndef LINX_DT_900_H
#define LINX_DT_900_H

#define START  		0x3C //start 
#define END  		0x3E //end
#define SDP 		0x21 //Send Data Packet
#define RNVC 		0x22 //Read_Non_volatile_Configurations
#define WNVC 		0x23 //Write Non-volatile Configurations
#define RIOC 		0x24 //Read I/O Configurations
#define RAVV 		0x26 //Read Analog Voltage Value
#define RDIOV 		0x27 //Read Digital IO Value
#define WDOV 		0x28 //Write Digital Output Value
#define RCN 		0x29 //Read Channel Number
#define RTXPL 		0x2B //Read TX Power Level
#define WTXPL 		0x2C //Write TX Power Level
#define RRS 		0x2D //Read Radio State
#define WRS 		0x2E //Write Radio State
#define RARSSI 		0x2F //Read Ambient RSSI
#define RFDC 		0x30 //Restore Factory Default Configurations
#define RDN 		0x31 //Read Device Name
#define RFV 		0x32 //Read Firmware Version
#define RMSN 		0x33 //Read Module Serial Number
#define RFAC 		0x37 //Read Frequency Agility Configurations
#define WFAC 		0x38 //Write Frequency Agility Configurations
#define SBP 		0x39 //Send Broadcast Packet
#define RAM			0x3A //Read Associated Modules
#define DAM			0x3B //Delete Associated Module
#define RM			0x3C //Reset Module
#define RAMC		0x3D //Read Associated Module Count
#define CWS			0x42 //CW Signal
#define RAK			0x43 //Read AES Key
#define RMT 		0x47 //Read Module Temperature
#define WAK			0x44 //Write AES Key
#define ICM			0x7A //Initialization Complete Message


void Send_Data_Packet(unsigned char * address, unsigned char * dados, unsigned char len){
	unsigned char i;
	uart1_write(START);
	uart1_write(SDP);
	uart1_write(address[0]);
	uart1_write(address[1]);
	uart1_write(address[2]);
	uart1_write(address[3]);
	uart1_write(0x05+len);
	for(i = 0; i < len; i++){
		uart1_write(dados[i]);
	}
	uart1_write(END);
}

void Read_Non_volatile_Configurations (){
	uart1_write(START);
	uart1_write(RNVC);
	uart1_write(END);
}

void Write_Non_volatile_Configurations(unsigned char dtype, unsigned char * modulo_address,
									   unsigned char baud_rate, unsigned char channel_map, 
									   unsigned char TX_Power_Level, unsigned char *network_ID){
	uart1_write(START);
	uart1_write(WNVC);
	uart1_write(dtype);//01
	uart1_write(modulo_address[0]);//02
	uart1_write(modulo_address[1]);//03
	uart1_write(modulo_address[2]);//04
	uart1_write(modulo_address[3]);//05
	uart1_write(baud_rate);//06
	uart1_write(channel_map);//07
	uart1_write(0x00);//N/A //08
	uart1_write(TX_Power_Level);//09
	uart1_write(network_ID[0]);//10
	uart1_write(network_ID[1]);//11
	uart1_write(network_ID[2]);//12
	uart1_write(network_ID[3]);//13
	uart1_write(0x00);//14
	uart1_write(0x00);//15
	uart1_write(0x0b);//16
	uart1_write(0x00);//17
	uart1_write(0x00);//18
	uart1_write(0x00);//19
	uart1_write(0x00);//20
	uart1_write(0x2b);//21
	uart1_write(0x7e);//22
	uart1_write(0x15);//23
	uart1_write(0x16);//24
	uart1_write(0x28);//25
	uart1_write(0xae);//26
	uart1_write(0xd2);//27
	uart1_write(0xa6);//28
	uart1_write(0xab);//29
	uart1_write(0xf7);//30
	uart1_write(0x15);//31
	uart1_write(0x88);//32
	uart1_write(0x09);//33
	uart1_write(0xcf);//34
	uart1_write(0x4f);//35
	uart1_write(0x3c);//36
	uart1_write(0x00);//37
	uart1_write(0x00);//38
	uart1_write(0x00);//39
	uart1_write(0x00);//40
	uart1_write(0x00);//41
	uart1_write(0x00);//42
	uart1_write(0x00);//43
	uart1_write(0x00);//44
	uart1_write(0x00);//45
	uart1_write(0x00);//46
	uart1_write(0x00);//47
	uart1_write(0x00);//48
	uart1_write(0x00);//49
	uart1_write(0x00);//50
	uart1_write(0x00);//51
	uart1_write(0x00);//52
	uart1_write(0x00);//53
	uart1_write(0x00);//54
	uart1_write(END);
}

void Read_IO_Configurations(){
	uart1_write(START);
	uart1_write(RIOC);	
	uart1_write(0x00);
	uart1_write(0x00);
	uart1_write(END);
}

void Read_Analog_Voltage_Value(){
	uart1_write(START);
	uart1_write(RAVV);	
	uart1_write(0x00);
	uart1_write(0x00);
	uart1_write(END);	
}
void Read_Digital_IO_Value(){
	uart1_write(START);
	uart1_write(RDIOV);	
	uart1_write(0x00);
	uart1_write(0x00);
	uart1_write(END);	
}

void Write_Digital_Output_Value(){
	uart1_write(START);
	uart1_write(WDOV);	
	uart1_write(0x00);
	uart1_write(0x00);
	uart1_write(0x00);
	uart1_write(END);		
}

void Read_TX_Power_Level(){
	uart1_write(START);
	uart1_write(RTXPL);	
	uart1_write(END);		
}

void Read_Channel_Number(){
	uart1_write(START);
	uart1_write(RCN);	
	uart1_write(END);		
}

void Write_TX_Power_Level(unsigned char TX_Power_Level){
	uart1_write(START);
	uart1_write(WTXPL);	
	uart1_write(TX_Power_Level);
	uart1_write(END);	
}

void Read_Radio_State(){
	uart1_write(START);
	uart1_write(RRS);	
	uart1_write(END);	
}

void Write_Radio_State(unsigned char r_state){
	uart1_write(START);
	uart1_write(WRS);	
	uart1_write(r_state);
	uart1_write(END);
}

void Read_Ambient_RSSI(){
	uart1_write(START);
	uart1_write(RARSSI);	
	uart1_write(END);	
}

void Restore_Factory_Default_Configurations(){
	uart1_write(START);
	uart1_write(RFDC);	
	uart1_write(END);
}

void Read_Device_Name(){
	uart1_write(START);
	uart1_write(RDN);	
	uart1_write(END);	
}

void Read_Firmware_Version(){
	uart1_write(START);
	uart1_write(RFV);	
	uart1_write(END);	
}

void Read_Module_Serial_Number(){
	uart1_write(START);
	uart1_write(RMSN);	
	uart1_write(END);	
}

void Read_Frequency_Agility_Configurations(){
	uart1_write(START);
	uart1_write(RFAC);	
	uart1_write(END);	
}

void Write_Frequency_Agility_Configurations(unsigned char channel_map){
	uart1_write(START);
	uart1_write(WFAC);	
	uart1_write(channel_map);
	uart1_write(END);	
}

void Send_Broadcast_Packet(unsigned char * dados, unsigned char len){
	unsigned char i;
	uart1_write(START);
	uart1_write(SBP);	
	uart1_write(len+0x01);
	for(i = 0; i < len; i++){
		uart1_write(dados[i]);
	}
	uart1_write(END);	
}

void Read_Associated_Modules(){
	uart1_write(START);
	uart1_write(RAM);	
	uart1_write(END);		
}

void Delete_Associated_Module(unsigned char * address){
	uart1_write(START);
	uart1_write(DAM);
	uart1_write(address[0]);
	uart1_write(address[1]);
	uart1_write(address[2]);
	uart1_write(address[3]);	
	uart1_write(END);	
}
void Reset_Module(){
	uart1_write(START);
	uart1_write(RM);
	uart1_write(END);	
}

void Read_Associated_Module_Count(){
	uart1_write(START);
	uart1_write(RAMC);
	uart1_write(END);	
}

void CW_Signal(unsigned char channel, unsigned char TX_Power_Level){
	uart1_write(START);
	uart1_write(CWS);
	uart1_write(channel);
	uart1_write(TX_Power_Level);
	uart1_write(END);		
}

void Read_AES_Key(){
	uart1_write(START);
	uart1_write(RAK);
	uart1_write(END);	
}

void Write_AES_Key(unsigned char * key){//key = 16bytes
	unsigned char i;
	uart1_write(START);
	uart1_write(WAK);
	for(i = 0; i < 16; i++){
		uart1_write(key[i]);
	}
	uart1_write(END);
}

void Read_Module_Temperature(){
	uart1_write(START);
	uart1_write(RMT);
	uart1_write(END);
}

void Initialization_Complete_Message(unsigned char DType){
	uart1_write(START);
	uart1_write(ICM);
	uart1_write(DType);
	uart1_write(END);	
}
#endif