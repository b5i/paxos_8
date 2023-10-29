#ifndef BROWSER_HPP
#define BROWSER_HPP

#include "../../widgets/gui/iframe/iframe.hpp"
#include "../../interface/filestream.hpp"
#include "../../web/web.hpp"


class Browser : public CppAppContainer
{
    public:
    void main()
    {
        bool exit = false;
        bool mode = false;
        std::string url = "http://paxo.fr";

        while (!exit)
        {
            Window win("browser");
            win.setMarginX(0);

            Button* buttonData = new Button(10, 0, 100, 30, "files"); win.addChild(buttonData);
            Button* buttonInternet = new Button(320-10-100, 0, 100, 30, "internet"); win.addChild(buttonInternet);
            if(!mode)
                buttonData->setBackgroundColor(COLOR_SUCCESS);
            else
                buttonInternet->setBackgroundColor(COLOR_SUCCESS);

            std::string html;

            if(mode)
            {
                HttpClient client;
                html = client.get("https://www.textise.net/showText.aspx?strURL=" + url);
            }
            else
            {
                storage::FileStream file("apps/browser/data.html", storage::OPEN_MODE::READ);
                html = file.read();
                file.close();
            }

            Iframe* iframe = new Iframe(html, 0, 50, 310, 480-CONTROL_BAR_SIZE-win.getMarginY()-50);
            win.addChild(iframe);

            while (!home_button.pressed())
            {
                win.updateAll();
                #ifdef BUILD_EMU
                    SDL_Delay(20);
                #endif

                if(buttonData->isTouched())
                {
                    mode=false;
                    break;
                }

                if(buttonInternet->isTouched())
                {
                    mode=true;
                    break;
                }
            }
        }
        
    }
};

#endif