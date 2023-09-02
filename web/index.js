const PIXEL_SIZE = 20;
const MAX_IMG_SIZE = 400;
class CGImage {
    constructor(width = 0, height = 0, pixels = null) {
        this.width = width;
        this.height = height;
        this.pixels = pixels;
        if (width != 0) {
            this.pixelSize = Math.ceil(MAX_IMG_SIZE / width);
        }
    }

    Render(ctx, x, y) {
        for (let row = 0; row < this.height; row++) {
            for (let col = 0; col < this.width; col++) {
                ctx.fillStyle = this.pixels[row * this.width + col];
                const screenX = col * this.pixelSize + x;
                const screenY = row * this.pixelSize + y;
                ctx.fillRect(screenX, screenY, this.pixelSize, this.pixelSize);
            }
        }
    }
}


async function parseImage(file) {
    const inputStr = await fetch(file)
        .then((response) => {
        if (!response.ok) {
            throw new Error(`Fetching ${file} HTTP error: ${response.status}`);
        }
        return response.text();
        })
        .catch((error) => {
            console.error(`${error.message}`)
        });
    const imageStr = inputStr.trim();

    const size = imageStr.slice(0, 5).split(' ');

    const image = new CGImage(parseInt(size[0]), parseInt(size[1]));

    image.pixels = imageStr.slice(5).split(' ');
    for (idx in image.pixels) {
        strColor = image.pixels[idx];
        if (strColor.startsWith('\r\n')) {
            strColor = strColor.slice(2);
        }
        const withoutAlpha = strColor.slice(2);
        const blue = withoutAlpha.slice(0, 2);
        const green = withoutAlpha.slice(2, 4);
        const red = withoutAlpha.slice(4, 6);

        image.pixels[idx] = '#' + red + green + blue;
    }
    return image;
}

window.onload = async () => {
    const canvas = document.getElementById('app');
    const ctx = canvas.getContext('2d');
    let images = []

    const imageStr = await fetch('web/image_list.txt').then(x => x.text());
    const imageList = imageStr.split('\n');
    const pad = 10;
    const maxCols = 3;

    canvas.width = maxCols * (MAX_IMG_SIZE + pad);
    canvas.height = Math.ceil(imageList.length / maxCols) * (MAX_IMG_SIZE + pad);

    imageList.forEach(async (filepath) => {
        images.push(parseImage(filepath));
    });

    images.forEach(async (img, idx) => {
        image = await img;
        let x = idx % maxCols * MAX_IMG_SIZE;
        let y = Math.floor(idx / maxCols) * MAX_IMG_SIZE;
        if (x > 0) { x += pad * (idx % maxCols); }
        if (y > 0) { y += pad * (Math.floor(idx / maxCols)); }
        await image.Render(ctx, x, y);
    });

}