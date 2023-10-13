window.onload = () => {
    const appElement = document.getElementById('app');

    const images = [
        'web/Images/rainbow_tri.svg',
        'web/Images/logo.svg',
        'web/Images/rainbow_square.svg',
        'web/Images/gradient_circle.svg',
        'web/Images/gradient_square.svg',
        'web/Images/font_render.svg',
        'web/Images/transparent_circle.svg',
        'web/Images/dots.svg',
        'web/Images/line_bezier.svg',
    ];
    images.forEach((fileName) => {
        const imgElement = document.createElement('img');
        imgElement.setAttribute('src', fileName);
        appElement.appendChild(imgElement);
    });

}