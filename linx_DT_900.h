#ifndef LINX_DT_900_H
#define LINX_DT_900_H

#define START               0x3C //start 
#define END                 0x3E //end
#define SDP                 0x21 //Send Data Packet
#define RNVC                0x22 //Read_Non_volatile_Configurations
#define WNVC                0x23 //Write Non-volatile Configurations
#define RIOC                0x24 //Read I/O Configurations
#define RAVV                0x26 //Read Analog Voltage Value
#define RDIOV               0x27 //Read Digital IO Value
#define WDOV                0x28 //Write Digital Output Value
#define RCN                 0x29 //Read Channel Number
#define RTXPL               0x2B //Read TX Power Level
#define WTXPL               0x2C //Write TX Power Level
#define RRS                 0x2D //Read Radio State
#define WRS                 0x2E //Write Radio State
#define RARSSI              0x2F //Read Ambient RSSI
#define RFDC                0x30 //Restore Factory Default Configurations
#define RDN                 0x31 //Read Device Name
#define RFV                 0x32 //Read Firmware Version
#define RMSN                0x33 //Read Module Serial Number
#define RFAC                0x37 //Read Frequency Agility Configurations
#define WFAC                0x38 //Write Frequency Agility Configurations
#define SBP                 0x39 //Send Broadcast Packet
#define RAM                 0x3A //Read Associated Modules
#define DAM                 0x3B //Delete Associated Module
#define RM                  0x3C //Reset Module
#define RAMC                0x3D //Read Associated Module Count
#define OCWS                0x42 //Output CW Signal
#define RAK                 0x43 //Read AES Key
#define RMT                 0x47 //Read Module Temperature
#define WAK                 0x44 //Write AES Key
#define ICM                 0x7A //Initialization Complete Message

//type device
#define AP                  0x31
#define RE                  0x32
#define ED                  0x33

#define DELAY_100MS         delay_ms(100)   

unsigned char vet_channel_map[14] = {0x11, 0x12, 0x14, 0x18, 
                                     0x23, 0x26, 0x29, 0x2A, 0x2C,
                                     0x37, 0x3B, 0x3D, 0x3E, 
                                     0x4F};

struct response{
    unsigned char param[64];
    unsigned char i;
    unsigned char length;
}__Response;

struct config_radio{
    unsigned char dtype;
    unsigned char baud_rate;
    unsigned char channel_map;
    unsigned char TX_Power_Level;
    unsigned char modulo_address[4];
    unsigned char network_ID[4];
    unsigned char address_AP[4];
}__Config_radio;

void clear_response(){
    unsigned char i;
    for (i= 0; i < __Response.i; i++){
        __Response.param[i] = 0x00;
    }
    __Response.i = 0;
    __Response.length = 0;
}

void Send_Data_Packet(unsigned char * address, unsigned char * dados, unsigned char len){
    unsigned char i;

    clear_response();

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
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Non_volatile_Configurations (){
    clear_response();
    uart1_write(START);
    uart1_write(RNVC);
    uart1_write(END);
    __Response.length = 58;
    DELAY_100MS;
}

void Write_Non_volatile_Configurations(){
    clear_response();
    uart1_write(START);
    uart1_write(WNVC);
    uart1_write(__Config_radio.dtype);//01
    uart1_write(__Config_radio.modulo_address[0]);//02
    uart1_write(__Config_radio.modulo_address[1]);//03
    uart1_write(__Config_radio.modulo_address[2]);//04
    uart1_write(__Config_radio.modulo_address[3]);//05
    uart1_write(__Config_radio.baud_rate);//06
    uart1_write(__Config_radio.channel_map);//07
    uart1_write(0x00);//N/A //08
    uart1_write(__Config_radio.TX_Power_Level);//09
    uart1_write(__Config_radio.network_ID[0]);//10
    uart1_write(__Config_radio.network_ID[1]);//11
    uart1_write(__Config_radio.network_ID[2]);//12
    uart1_write(__Config_radio.network_ID[3]);//13
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
    __Response.length = 4;
    DELAY_100MS;
}

void Read_IO_Configurations(){
    clear_response();
    uart1_write(START);
    uart1_write(RIOC);  
    uart1_write(0x00);
    uart1_write(0x00);
    uart1_write(END);
    __Response.length = 8;
    DELAY_100MS;
}

void Read_Analog_Voltage_Value(){
    uart1_write(START);
    uart1_write(RAVV);  
    uart1_write(0x00);
    uart1_write(0x00);
    uart1_write(END);   
    __Response.length = 8;
    DELAY_100MS;
}
void Read_Digital_IO_Value(){
    clear_response();
    uart1_write(START);
    uart1_write(RDIOV); 
    uart1_write(0x00);
    uart1_write(0x00);
    uart1_write(END);   
    __Response.length = 7;
    DELAY_100MS;
}

void Write_Digital_Output_Value(){
    clear_response();
    uart1_write(START);
    uart1_write(WDOV);  
    uart1_write(0x00);
    uart1_write(0x00);
    uart1_write(0x00);
    uart1_write(END);   
    __Response.length = 4;  
    DELAY_100MS;
}

void Read_TX_Power_Level(){
    clear_response();
    uart1_write(START);
    uart1_write(RTXPL); 
    uart1_write(END);       
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Channel_Number(){
    clear_response();
    uart1_write(START);
    uart1_write(RCN);   
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;        
}

void Write_TX_Power_Level(){
    clear_response();
    uart1_write(START);
    uart1_write(WTXPL); 
    uart1_write(__Config_radio.TX_Power_Level);
    uart1_write(END);   
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Radio_State(){
    clear_response();
    uart1_write(START);
    uart1_write(RRS);   
    uart1_write(END);
    __Response.length = 4;  
    DELAY_100MS;
}

void Write_Radio_State(unsigned char r_state){
    clear_response();
    uart1_write(START);
    uart1_write(WRS);   
    uart1_write(r_state);
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Ambient_RSSI(){
    clear_response();
    uart1_write(START);
    uart1_write(RARSSI);    
    uart1_write(END);   
    __Response.length = 4;
    DELAY_100MS;
}

void Restore_Factory_Default_Configurations(){
    clear_response();
    uart1_write(START);
    uart1_write(RFDC);  
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Device_Name(){
    clear_response();
    uart1_write(START);
    uart1_write(RDN);   
    uart1_write(END);   
    __Response.length = 14;
    DELAY_100MS;
}

void Read_Module_Serial_Number(){
    clear_response();
    uart1_write(START);
    uart1_write(RMSN);  
    uart1_write(END);
    __Response.length = 7;         
    DELAY_100MS;
}

void Read_Firmware_Version(){
    clear_response();
    uart1_write(START);
    uart1_write(RFV);   
    uart1_write(END);
    __Response.length = 7;
    DELAY_100MS;
}


void Read_Frequency_Agility_Configurations(){
    clear_response();
    uart1_write(START);
    uart1_write(RFAC);  
    uart1_write(END);   
    __Response.length = 4;
    DELAY_100MS;
}

void Write_Frequency_Agility_Configurations(){
    clear_response();
    uart1_write(START);
    uart1_write(WFAC);  
    uart1_write(__Config_radio.channel_map);
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;
}

void Send_Broadcast_Packet(unsigned char * dados, unsigned char len){
    unsigned char i;
    clear_response();
    uart1_write(START);
    uart1_write(SBP);   
    uart1_write(len+0x01);
    for(i = 0; i < len; i++){
        uart1_write(dados[i]);
    }
    uart1_write(END);
    __Response.length = 4;  
    DELAY_100MS;
}

void Read_Associated_Modules(){
    clear_response();
    uart1_write(START);
    uart1_write(RAM);   
    uart1_write(END);
    __Response.length = 4;      
    DELAY_100MS;
}

void Delete_Associated_Module(unsigned char * address){
    clear_response();
    uart1_write(START);
    uart1_write(DAM);
    uart1_write(address[0]);
    uart1_write(address[1]);
    uart1_write(address[2]);
    uart1_write(address[3]);    
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;
}
void Reset_Module(){
    clear_response();
    uart1_write(START);
    uart1_write(RM);
    uart1_write(END);
    __Response.length = 4;  
    DELAY_100MS;
}

void Read_Associated_Module_Count(){
    clear_response();
    uart1_write(START);
    uart1_write(RAMC);
    uart1_write(END);
    __Response.length = 4;  
    DELAY_100MS;
}

void Output_CW_Signal(){
    clear_response();
    uart1_write(START);
    uart1_write(OCWS);
    uart1_write(__Config_radio.channel_map);
    uart1_write(__Config_radio.TX_Power_Level);
    uart1_write(END);
    __Response.length = 4;  
    DELAY_100MS;
}

void Read_AES_Key(){
    clear_response();
    uart1_write(START);
    uart1_write(RAK);
    uart1_write(END);
    __Response.length = 19; 
    DELAY_100MS;
}

void Write_AES_Key(unsigned char * key){//key = 16bytes
    unsigned char i;
    clear_response();

    uart1_write(START);
    uart1_write(WAK);
    for(i = 0; i < 16; i++){
        uart1_write(key[i]);
    }
    uart1_write(END);
    __Response.length = 4;
    DELAY_100MS;
}

void Read_Module_Temperature(){
    clear_response();
    uart1_write(START);
    uart1_write(RMT);
    uart1_write(END);
    __Response.length = 6;
    DELAY_100MS;
}

/************************GENERAL PURPOSE FUNCTIONS ***************************/
int Response_default(unsigned char cmd){
    if(__Response.param[0] != START) return 0;
    if(__Response.param[1] != cmd) return 0;
    if(__Response.param[2] != 0x00) return 0;
    if(__Response.param[3] != END) return 0;
    __Response.param[0] = 0x00;
    __Response.param[1] = 0x00;
    __Response.param[2] = 0x00;
    __Response.param[3] = 0x00;
    clear_response();
    return 1;
}

int Initialization_Complete_Message(){
    if(__Response.param[0] != START) return 0;
    if(__Response.param[1] != ICM) return 0;
    if(__Response.param[2] != __Config_radio.dtype) return 0;
    if(__Response.param[3] != END) return 0;
    __Response.param[0] = 0x00;
    __Response.param[1] = 0x00;
    __Response.param[2] = 0x00;
    __Response.param[3] = 0x00;
    clear_response();
    return 1;
}

void load_config_radio(){
    Write_Non_volatile_Configurations();
    while(__Response.i < __Response.length);
    clear_response();
}


void set_dtype(unsigned char dtype){
    if(dtype == AP || dtype == RE || dtype == ED){
        __Config_radio.dtype = dtype;
    }
    else{
        __Config_radio.dtype = ED;//default -> 0x33
    }
}

unsigned char get_dtype(){
    return __Config_radio.dtype;
}

void set_channel_map(unsigned char channel_map){
    int i;
    for(i = 0; i < 14; i++){
        if(vet_channel_map[i] == channel_map){
            __Config_radio.channel_map = channel_map;
            return;
        }
    }
    __Config_radio.channel_map = 0x12;//default ->0b0001 0010
}

unsigned char get_channel_map(){
    return __Config_radio.channel_map;
}

void set_TX_power_level(unsigned char TX_Power_Level){
    if( TX_Power_Level >= 0x00 && TX_Power_Level <= 0x08){
        __Config_radio.TX_Power_Level = TX_Power_Level;
    }
    else{
        __Config_radio.TX_Power_Level = 0x07;//default -> 7
    }
}

unsigned char get_TX_power_level(){
    return __Config_radio.TX_Power_Level;
}

void set_baud_rate(unsigned char baud_rate){
    if( baud_rate >= 0x00 && baud_rate <= 0x09){
        __Config_radio.baud_rate = baud_rate;
    }
    else{
        __Config_radio.baud_rate = 0x03;//defalut -> 9600
    }
}

unsigned char get_baud_rate(){
    return __Config_radio.baud_rate;
}

void set_network_ID(unsigned char * addr){
    __Config_radio.network_ID[0] = addr[0];
    __Config_radio.network_ID[1] = addr[1];
    __Config_radio.network_ID[2] = addr[2];
    __Config_radio.network_ID[3] = addr[3];
}

void set_modulo_address(unsigned char * addr){
    __Config_radio.modulo_address[0] = addr[0];
    __Config_radio.modulo_address[1] = addr[1];
    __Config_radio.modulo_address[2] = addr[2];
    __Config_radio.modulo_address[3] = addr[3];

}

void set_address_AP(unsigned char * addr){
    __Config_radio.address_AP[0] = addr[0];
    __Config_radio.address_AP[1] = addr[1];
    __Config_radio.address_AP[2] = addr[2];
    __Config_radio.address_AP[3] = addr[3];
}

void constructor_DT_900(struct config_radio config_r){//constructor
    __Response.i = 0;
    __Response.length = 0;
    set_dtype(config_r.dtype);
    set_baud_rate(config_r.baud_rate);
    set_channel_map(config_r.channel_map);
    set_TX_power_level(config_r.TX_Power_Level);
    set_modulo_address(config_r.modulo_address);
    set_address_AP(config_r.address_AP);
    set_network_ID(config_r.network_ID);
    clear_response();
}

#endif