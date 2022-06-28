// Crear y modificar una cookie de nombre name
document.cookie = "name=value";

// Comprobar si existe una cookie de nombre name
const exists = document.cookie.split(';').some(function(item) {
   return item.trim().indexOf('name=') == 0;
});

// Obtener el valor de la cookie de nombre name
const value = document.cookie.split('; ').find(row => row.startsWith('name=')).split('=')[1];

// Eliminar la cookie cookie de nombre name
document.cookie = "name=; expires=Thu, 01 Jan 1970 00:00:00 GMT";


//Atrapar el envío del formulario HTML y gestionarlo con javascript
uploadForm.onsubmit = async (e) => {
    e.preventDefault();

    //Datos del formulario:
    let data = new FormData(uploadForm);

    //Envío y obtención de respuesta en formato texto
    let response = await fetch('./upload.exe',
        {
            method: 'POST',
            body: data
        });

    let result = await response.text();

    //recargar el iframe para ver nuevos archivos subidos
    document.getElementById('dirIframe').contentWindow.location.reload();
    //mostrar el mensaje del servidor:
    alert(result);
};