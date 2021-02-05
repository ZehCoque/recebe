import QtQuick 2.0
import QtQuick.Controls 2.15
//import EnviaComando 1.0

Page {
    visible: true
    width: 640
    height: 480
    title: "Enviar Comando"
    id:page
    Loader{
        id : sendCommandWindow
    }



    TextArea{
        //propriedades de texto
        text: "Digite o tópico e o conteúdo que deseja enviar"
        wrapMode: "WordWrap"
        horizontalAlignment: TextEdit.AlignHCenter
        readOnly: true

        //propriedades de posição
        width: parent.width - 50
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30

    }

    TextField{
        id: topic
        placeholderText: "Tópico"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
        horizontalAlignment: "AlignHCenter"
    }

    TextArea{
        id: content
        placeholderText: "Conteúdo"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 160
        horizontalAlignment: "AlignHCenter"
        width: parent.width-50
    }

//    EnviaComando{
//        id: enviaComando
//    }

    //Botão p/ enviar o comando
    Button {
        id: send
        text:"Enviar"
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height - 120

        MouseArea{
            id: recebeButtonMouseArea
            objectName: recebeButtonMouseArea
            anchors.fill: parent

            signal qmlSignal(string msg)

            onClicked: {
                //Receber comando
                parent.qmlSignal("From yes")
            }
        }

    }

}
