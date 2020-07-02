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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int h = 0; h < height; h ++)
    {
        for (int w = 0; w < width; w ++)
        {
            sepiaRed = round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);
            sepiaGreen = round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            sepiaBlue = round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);
//Ensure SepiaRed is an int between 0 ans 255
            if (sepiaRed >= 0 && sepiaRed <= 255)
            {
                image[h][w].rgbtRed = sepiaRed;
            }
            else if (sepiaRed < 0)
            {
                image[h][w].rgbtRed = 0;
            }
            else if (sepiaRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
//Ensure SepiaGreen is an int between 0 ans 255
            if (sepiaGreen >= 0 && sepiaGreen <= 255)
            {
                image[h][w].rgbtGreen = sepiaGreen;;
            }
            else if (sepiaGreen < 0)
            {
                image[h][w].rgbtGreen = 0;
            }
            else if (sepiaGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
//Ensure SepiaBlue is an int between 0 ans 255
            if (sepiaBlue >= 0 && sepiaBlue <= 255)
            {
                image[h][w].rgbtBlue = sepiaBlue;;
            }
            else if (sepiaBlue < 0)
            {
                image[h][w].rgbtBlue = 0;
            }
            else if (sepiaBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
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
