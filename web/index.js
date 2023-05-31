const PIXEL_SIZE = 20;
const MAX_IMG_SIZE = 400;
class CGImage {
    constructor(width = 0, height = 0, pixels = null) {
        this.width = width;
        this.height = height;
        this.pixels = pixels;
        if (width != 0) {
            this.pixel_size = MAX_IMG_SIZE / width;
        }
    }

    Render(ctx, x, y) {
        for (let row = 0; row < this.height; row++) {
            for (let col = 0; col < this.width; col++) {
                ctx.fillStyle = this.pixels[row * this.width + col];
                const px = col * this.pixel_size + x;
                const py = row * this.pixel_size + y;
                ctx.fillRect(px, py, this.pixel_size, this.pixel_size);
            }
        }
    }
}


async function parseImage(file) {
    const input_str = await fetch(file)
        .then((response) => {
        if (!response.ok) {
            throw new Error(`Fetching ${file} HTTP error: ${response.status}`);
        }
        return response.text();
        })
        .catch((error) => {
            console.error(`${error.message}`)
        });
    const image_str = input_str.trim();

    const size = image_str.slice(0, 5).split(" ");

    const image = new CGImage(parseInt(size[0]), parseInt(size[1]));

    image.pixels = image_str.slice(5).split(' ');
    for (idx in image.pixels) {
        str_color = image.pixels[idx];
        if (str_color.startsWith("\r\n")) {
            str_color = str_color.slice(2);
        }
        const wout_alpha = str_color.slice(2);
        const red = wout_alpha.slice(0, 2);
        const green = wout_alpha.slice(2, 4);
        const blue = wout_alpha.slice(4, 6);

        image.pixels[idx] = "#" + blue + green + red;
    }
    return image;
}

window.onload = async () => {
    const canvas = document.getElementById("app");
    const ctx = canvas.getContext("2d");

    let images = []

    const imageStr = await fetch('web/image_list.txt').then(x => x.text());
    const imageList = imageStr.split('\n');
    const pad = 10;
    canvas.height = Math.ceil(imageList.length / 3) * (MAX_IMG_SIZE) + pad;
    console.log(canvas.height);
    imageList.forEach(async (filepath) => {
        images.push(parseImage(filepath));
    });

    images.forEach(async (img, idx) => {
        image = await img;

        const imgWidth = image.width * image.pixel_size;
        const imgHeight = image.height * image.pixel_size;
        const x = ((idx * imgWidth) % canvas.width);
        const y = (Math.floor((idx * imgHeight) / canvas.width)) * imgHeight;
        ctx.fillStyle = '#181818';
        ctx.fillRect(x, y, imgWidth + (pad * 2), imgHeight + (pad * 2));
        image.Render(ctx, x + pad, y + pad);
    });

}