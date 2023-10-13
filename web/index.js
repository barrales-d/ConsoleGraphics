window.onload = async () => {
    const imgDirectory = await fetch('web/Images/')
        .then((response) => {
            if (!response.ok) {
                throw new Error(`Fetching ${file} HTTP error: ${response.status}`);
            }
            return response.text();
        })
        .catch((error) => {
            console.error(`${error.message}`)
        });
    var images = imgDirectory.split('<li>');
    images.shift();

    const appElement = document.getElementById('app');

    images.forEach((element) => {
        var fileName = 'web/Images/' + element.split('\"')[1];
        const imgElement = document.createElement('img');
        imgElement.setAttribute('src', fileName);
        appElement.appendChild(imgElement);
    });

}