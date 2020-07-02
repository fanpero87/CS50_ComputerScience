#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            avg = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE mirror [height][width]; //Temporary 2D matrix to store the reflected elements
    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            mirror[h][width - 1 - w] = image[h][w]; //Copy the elements to the temporary matrix
        }
        for (int w = 0; w < width; w ++)
        {
            image[h][w] = mirror[h][w]; //Copy the relefected elements to the original matrix
        }
    }
    return;
}

//New Function that will blur each pixel
RGBTRIPLE blurred_image(int h, int w, int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed = 0;
    int sumGreen = 0;
    int sumBlue = 0;
    int avgCount = 0;

    for (int dh = -1; dh <= 1; dh ++) //Loop for the 9 different positions to calculate the avg of the color
    {
        for (int dw = -1; dw <= 1; dw ++)
        {
            int new_h = dh + h;
            int new_w = dw + w;
            if (new_h >= 0 && new_h < height && new_w >= 0 && new_w < width) //Check if the pixel is inside the array
            {
                avgCount ++;
                sumRed += image[new_h][new_w].rgbtRed;
                sumGreen += image[new_h][new_w].rgbtGreen;
                sumBlue += image[new_h][new_w].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) sumRed / avgCount);
    blurred_pixel.rgbtGreen = round((float) sumGreen / avgCount);
    blurred_pixel.rgbtBlue = round((float) sumBlue / avgCount);
    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurry [height][width]; //Temporary 2D matrix to store the blurred elements
    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            blurry[h][w] = blurred_image(h, w, height, width, image); //Send each pixel to be blurred and save it in a new image
        }
    }

    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            image[h][w] = blurry[h][w]; //Copy each plurred pixel back into the original image
        }
    }
    return;
}

//New Function that calculate the edge per pixel
RGBTRIPLE createEdge(int h, int w, int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}; //Sobel operator matrix
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; //Sobel operator matrix
    int valueRedX = 0, valueGreenX = 0, valueBlueX = 0;
    int valueRedY = 0, valueGreenY = 0, valueBlueY = 0;
    int squareRed = 0, squareGreen = 0, squareBlue = 0;

    for (int dh = -1; dh <= 1; dh ++) //Loop for the 9 different positions of the 3x3 grid
    {
        for (int dw = -1; dw <= 1; dw ++)
        {
            int new_h = dh + h;
            int new_w = dw + w;
            if (new_h >= 0 && new_h < height && new_w >= 0 && new_w < width) //Check if the pixel is inside the image
            {
                int weightX = Gx[dh + 1][dw + 1]; //Run the Sobel Operator value of each position per pixel (X)
                valueRedX += weightX * image[new_h][new_w].rgbtRed;
                valueGreenX += weightX * image[new_h][new_w].rgbtGreen;
                valueBlueX += weightX * image[new_h][new_w].rgbtBlue;

                int weightY = Gy[dh + 1][dw + 1]; //Run the Sobel Operator value of each position per pixel (Y)
                valueRedY += weightY * image[new_h][new_w].rgbtRed;
                valueGreenY += weightY * image[new_h][new_w].rgbtGreen;
                valueBlueY += weightY * image[new_h][new_w].rgbtBlue;
            }
        }
    }
// Combine and calculate the Square Root for each color
    squareRed = round(sqrt(valueRedX * valueRedX + valueRedY * valueRedY));
    squareGreen = round(sqrt(valueGreenX * valueGreenX + valueGreenY * valueGreenY));
    squareBlue = round(sqrt(valueBlueX * valueBlueX + valueBlueY * valueBlueY));

// Check each value is capped at 255
    if (squareRed > 255)
    {
        squareRed = 255;
    }
    if (squareGreen > 255)
    {
        squareGreen = 255;
    }
    if (squareBlue > 255)
    {
        squareBlue = 255;
    }

    RGBTRIPLE edge_pixel; //Return each pixel after the edge process
    edge_pixel.rgbtRed = squareRed;
    edge_pixel.rgbtGreen = squareGreen;
    edge_pixel.rgbtBlue = squareBlue;
    return edge_pixel;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edgeImage [height][width]; //Temporary 2D matrix to store the new elements
    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            edgeImage[h][w] = createEdge(h, w, height, width, image); //Send each pixel to be blurred and save it in a new image
        }
    }

    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            image[h][w] = edgeImage[h][w]; //Copy each plurred pixel back into the original image
        }
    }
    return;
}
