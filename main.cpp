#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Media{
    private:
        string nombreArchivo;
    public:
        Media(){
            nombreArchivo = "Archivo sin nombre";
        }
        Media(string pnombrearchivo){
            nombreArchivo = pnombrearchivo;
        }
        string getNombreArchivo(){
            return nombreArchivo;
        }
        void setNombreArchivo(string pnombrearchivo){
            nombreArchivo = pnombrearchivo;
        }
        void getInfo(){
            cout << "Nombre del archivo: "  << endl;
        }
};

class MediaAudio : public Media{
    private:
        string duracion;
        string formato;
    public:
        MediaAudio(){
            this->setNombreArchivo("");
            duracion =  "";
            formato = "";
        }
        MediaAudio(string pnombre, string pduracion, string pformato){
            this->setNombreArchivo(pnombre);
            duracion =  pduracion;
            formato =  pformato;
        }
        void getInfo(){
            cout << "Nombre del archivo: " <<  this->getNombreArchivo() << "."  << formato << "  Duracion: "   << duracion << endl;
        }
};

class MediaVideo : public Media{
    private:
        string duracion;
        string formato;
    public:
        MediaVideo(){
            this->setNombreArchivo("");
            duracion =  "";
            formato = "";
        }
        MediaVideo(string pnombre, string pduracion, string pformato){
            this->setNombreArchivo(pnombre);
            duracion =  pduracion;
            formato =  pformato;
        }
        void getInfo(){
            cout << "Nombre del archivo: " <<  this->getNombreArchivo() << "."  << formato << "  Duracion: "   << duracion << endl;
        }
};

class MediaFoto : public Media{
    private:
        string formato;
    public:
        MediaFoto(){
            this->setNombreArchivo("");
            formato = "";
        }
        MediaFoto(string pnombre, string pformato){
            this->setNombreArchivo(pnombre);
            formato =  pformato;
        }
        void getInfo(){
            cout << "Nombre del archivo: " <<  this->getNombreArchivo() << "."  << formato << endl;
        }
};

class Noticia{
    private:
        string titulo;
        string fecha;
        string autor;
    public:
        Noticia(){
            titulo = "Sin titulo";
            fecha = "Sin fecha";
            autor = "Sin autor";
        }
        Noticia(string ptitulo, string pfecha, string pautor){
            titulo = ptitulo;
            fecha = pfecha;
            autor = pautor;
        }
        string getTitulo(){
            return titulo;
        }
        string getFecha(){
            return fecha;
        }
        string getAutor(){
            return autor;
        }
        void setTitulo(string ptitulo){
            titulo = ptitulo;
        }
        void setFecha(string pfecha){
            fecha = pfecha;
        }
        void setAutor(string pautor){
            autor = pautor;
        }
        void getInfo(){
            cout << "Noticia: " << titulo << endl << "Fecha: " << fecha << endl << "Autor: " << autor << endl;
        }
};

class NoticiaPaper : public Noticia{
    private:
        string fotoLink;
    public:
        NoticiaPaper(){
            this->setTitulo("");
            this->setFecha("");
            this->setAutor("");
            fotoLink = "";
        }
        NoticiaPaper(string ptitulo, string pfecha, string pautor, string pfotoLink){
            this->setTitulo(ptitulo);
            this->setFecha(pfecha);
            this->setAutor(pautor);
            fotoLink = pfotoLink;
        }
        string getFotoLink(){
            return fotoLink;
        }
        void setFotoLink(string pFotoLink){
            fotoLink = pFotoLink;
        }
        void getInfo(){
            cout << "Noticia: " << this->getTitulo() << endl << "Fecha: " << this->getFecha() << endl << "Autor: " << this->getAutor() << endl;
            cout << "Link a imagen: " << fotoLink << endl;
        }
};

class NoticiaDigital : public Noticia{
    private:
        vector<Media> listaMedia;
    public:
        NoticiaDigital(){
            this->setTitulo("");
            this->setFecha("");
            this->setAutor("");
            listaMedia = {};
        }
        NoticiaDigital(string ptitulo, string pfecha, string pautor,vector<Media> pListaMedia){
            this->setTitulo(ptitulo);
            this->setFecha(pfecha);
            this->setAutor(pautor);
            listaMedia = pListaMedia;
        }
        vector<Media> getListaMedia(){
            return listaMedia;
        }
        void setListaMedia(vector<Media> pListaMedia){
            listaMedia = pListaMedia;
        }
        void pushListaMedia(Media newItem){
            listaMedia.push_back(newItem);
        }
        void popListaMedia(){
            listaMedia.pop_back();
        }
        void getInfo(){
            cout << "Noticia: " << this->getTitulo() << endl << "Fecha: " << this->getFecha() << endl << "Autor: " << this->getAutor() << endl;
            cout << "Lista de archivos multimedia: " << endl;
            for (int i = 0; i < listaMedia.size(); i++){
                Media tmp = listaMedia[i];
                tmp.getInfo();
            }
        }
};

class NoticiaRadio : public Noticia{
    private:
        string audioLink;
    public:
        NoticiaRadio(){
            this->setTitulo("");
            this->setFecha("");
            this->setAutor("");
            audioLink = "";
        }
        NoticiaRadio(string ptitulo, string pfecha, string pautor, string paudioLink){
            this->setTitulo(ptitulo);
            this->setFecha(pfecha);
            this->setAutor(pautor);
            audioLink = paudioLink;
        }
        string getAudioLink(){
            return audioLink;
        }
        void setAudioLink(string paudioLink){
            audioLink = paudioLink;
        }
        void getInfo(){
            cout << "Noticia: " << this->getTitulo() << endl << "Fecha: " << this->getFecha() << endl << "Autor: " << this->getAutor() << endl;
            cout << "Link al audio: " << audioLink << endl;
        }
};

int main(){
    cout << "Noticia:" << endl;
    Noticia noticia1("Muerte de actor","12 de abril 2021","Kenneth Palacios");
    noticia1.getInfo();
    cout << endl << "NoticiaPaper:" << endl;
    NoticiaPaper noticiaPaper1("Accidente de transito", "02 de marzo 2022", "Hannah Schwarz","www.foto.com");
    noticiaPaper1.getInfo();
    cout << endl << "NoticiaDigital:" << endl;
    MediaAudio media1("Bombardeo","3:00","mp3");
    MediaFoto media2("Foto de un pueblo Ucraniano","jpg");
    MediaVideo media3("Video","0:43","mov");
    cout << endl << endl;
    media1.getInfo();
    NoticiaDigital noticiaDigital1("Guerra en Ucrania", "28 de febrero 2022", "Richard Rodriguez", {media1,media2,media3});
    noticiaDigital1.getInfo();
    cout << endl << "NoticiaRadio:" << endl;
    NoticiaRadio noticiaRadio1("Empleabilidad en Costa Rica","02 de marzo 2022","Sabrina Guilarte", "www.audio.com");
    noticiaRadio1.getInfo();

    return 0;
}