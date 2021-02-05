import QtQuick 2.0
import QtQuick.Controls 2.15
import RecebeComando 1.0

Page {
    visible: true
    width: 640
    height: 480
    title: "Receber Comando"
    id:page
    Loader{
        id : sendCommandWindow
    }

    RecebeComando{
        id: recebeComando
        onMessageChanged: {
            //Toda vez que o sinal for emitido, o texto do content sera alterado
            content.text = recebeComando.msg
        }
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

        //propriedades de texto
        placeholderText: "Tópico"
        horizontalAlignment: "AlignHCenter"

        //propriedades de posição
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100

        //altera o valor da variavel text na classe C++ RecebeComando com qualquer alteracao de texto
        onTextEdited: {
            recebeComando.topic = topic.text;
        }
    }

    TextArea{
        id: content
        placeholderText: "Conteúdo"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 160
        horizontalAlignment: "AlignHCenter"
        width: parent.width-50
        readOnly: true

    }




}
