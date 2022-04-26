import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import server 1.0
import client 1.0
import session 1.0


Window {

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property variant clientList : []
    property int clientNumber: 0

    LocalSocketServer{
        id: localSocketServer
    }
//    LocalSocketClient{
//        id: localSocketClient
//    }

    ClientSessions{
        id: clientSessions
    }

    ListModel{
        id: clientModel
    }

//    function initiateClient(){
//        console.log("client initialized");
//        localSocketClient.connectToServer();
//        clientText.text = localSocketClient.getServerPath()
//    }

    function createNewClient(){
        console.log("create new client")
        clientNumber = clientSessions.createNewClientSocket()
        clientList.push(clientNumber)
        clientSessions.connectClientToServer(clientNumber)

    }

    Row{
        padding: 50
        Column{

            padding: 10
            Label{
                id: client
                text: "ClientSet"
            }
            TextField{
                id: clientText
                text: client.text
            }
            ListView{

            }

            Button{
                id: clientInit
                text: "Create New Client"
                onClicked: createNewClient()
            }

        }
        Column{
            padding: 10

            Label{
                id: server
                text: "Server"
            }
            TextField{
                id: serverName
                text: "ServerName:- " + localSocketServer.getServerName()
            }


            Button{
                id: serverClick
                text: "Click!"
            }
        }




    }
}
