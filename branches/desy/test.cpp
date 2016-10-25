#include <amptek.h>
#include <iostream>
#include <sstream>

void request_sca(AmptekCommHandler* commHandler)
{
    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0x04);
    requestPacket->setPid2(0x01);
    requestPacket->calcAndFillChecksum();

    cout << "SCA REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(MIN_PACKET_LEN);
    commHandler->receive(responsePacket);
    cout << "SCA RESPONSE: " << endl << responsePacket->toString() << endl;

    delete requestPacket;
    delete responsePacket;	
}


void request_status(AmptekCommHandler* commHandler)
{
    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0x01);
    requestPacket->setPid2(0x01);
    requestPacket->calcAndFillChecksum();

    cout << "GET STATUS REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(MIN_PACKET_LEN);
    commHandler->receive(responsePacket);
    cout << "GET STATUS RESPONSE: " << endl << responsePacket->toString() << endl;

    delete requestPacket;
    delete responsePacket;	
}

void request_set_text_configuration(AmptekCommHandler* commHandler)
{
    string conf;
    cout << "Type text configuration:" << endl;
    cin >> conf;

    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0x20);
    requestPacket->setPid2(0x02);

    int len = conf.length();
    byte data[len];
    charToByte(conf.c_str(), data, len);
    requestPacket->setData(data, len);
    requestPacket->calcAndFillChecksum();

    cout << "SET CONFIGURATION REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(MIN_PACKET_LEN);
    commHandler->acknowledge(responsePacket);
    cout << "SET CONFIGURATION RESPONSE: " << endl << responsePacket->toString() << endl;

    delete requestPacket;
    delete responsePacket;	
}

void request_get_text_configuration(AmptekCommHandler* commHandler)
{
    string conf;
    cout << "Type text configuration query:" << endl;
    cin >> conf;

    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0x20);
    requestPacket->setPid2(0x03);

    int len = conf.length();
    byte data[len];
    charToByte(conf.c_str(), data, len);
    requestPacket->setData(data, len);
    requestPacket->calcAndFillChecksum();

    cout << "GET TEXT CONFIGURATION REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(MIN_PACKET_LEN);
    commHandler->receive(responsePacket);
    cout << "GET TEXT CONFIGURATION RESPONSE: " << endl << responsePacket->toString() << endl;

    delete requestPacket;
    delete responsePacket;
	
}

void request_spectrum(AmptekCommHandler* commHandler)
{
    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0x02);
    requestPacket->setPid2(0x01);
    requestPacket->calcAndFillChecksum();
    cout << "read_spectrum(): requestPacket.dataLength = " << requestPacket->dataLength << endl;

    cout << "SPECTRUM REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(6);
    commHandler->receiveSpectrum(responsePacket);

    cout << "SPECTRUM RESPONSE: " << endl << responsePacket->toString();
    delete requestPacket;
    delete responsePacket;
}

void request_echo(AmptekCommHandler* commHandler)
{
    Packet* requestPacket = new Packet(MIN_PACKET_LEN);
    requestPacket->initSync();
    requestPacket->setPid1(0xF1);
    requestPacket->setPid2(0x7F);

    char request_str[4] = "ABC";
    byte data[3];
    charToByte(request_str, data, 3);
    requestPacket->setData(data, 3);
    requestPacket->calcAndFillChecksum();

    cout << "ECHO REQUEST: " << endl << requestPacket->toString() << endl;

    commHandler->send(requestPacket);

    Packet* responsePacket = new Packet(MIN_PACKET_LEN);
    commHandler->receive(responsePacket);
    cout << "ECHO RESPONSE: " << endl << responsePacket->toString() << endl;

    delete requestPacket;
    delete responsePacket;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       return 1;
    }
    try
    {
        int portnr = atoi(argv[2]);
        AmptekCommHandler* commHandler = new AmptekCommHandler(argv[1], portnr);
        while(1)
        {
            cout << "Please select one of the testing option:" << endl;
            cout << "1 - echo request" << endl;
            cout << "2 - spectrum request" << endl; 
            cout << "3 - text configuration request" << endl;
            cout << "4 - text configuration query" << endl;
            cout << "5 - status request" << endl;
            cout << "6 - SCA request" << endl;
            int option;
            cin >> option;
            switch(option)
            {
                case 1:
                    request_echo(commHandler);
                    break;
                case 2:
                    request_spectrum(commHandler);
                    break;
                case 3:
                    request_set_text_configuration(commHandler);
                    break;
                case 4:
                    request_get_text_configuration(commHandler);
                    break;
                case 5:
                    request_status(commHandler);
                    break;
                case 6:
                    request_sca(commHandler);
                    break;
                default:
                    cout << "Wrong option. Exiting..." << endl;
                    return 1;
            }
        }
    }
    catch(AmptekException& e)
    {
        cout << "AMPTEK ERROR: \n" << e.description() << endl;
    }
    catch (exception& e)
    {
       std::stringstream ss;
       ss << "ERROR, in function " << __FUNCTION__ << ":" << std::endl
          << e.what() << std::endl << std::endl
          << __FILE__ << ":" << __LINE__;
       std::cerr << "\n--------\n" << ss.str() << "\n--------" << std::endl;
    }
    return 0;
}
