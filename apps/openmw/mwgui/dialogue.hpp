#ifndef MWGUI_DIALOGE_H
#define MWGUI_DIALOGE_H

#include <components/esm_store/store.hpp>

#include <openengine/gui/layout.hpp>

#include <boost/array.hpp>

namespace MWWorld
{
    class Environment;
}

/*
  This file contains the dialouge window
  Layout is defined by resources/mygui/openmw_dialogue_window_layout.xml.
 */

namespace MWGui
{
    class DialogeHistory;

    using namespace MyGUI;

    class DialogueWindow: public OEngine::GUI::Layout
    {
    public:
        DialogueWindow(MWWorld::Environment& environment);

        void open();

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Dialog finished, OK button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventBye;

    protected:
        void onSelectTopic(MyGUI::List* _sender, size_t _index);
        void onByeClicked(MyGUI::Widget* _sender);
        void onHistoryClicked(MyGUI::Widget* _sender);

    private:
        void updateOptions();

        MWWorld::Environment& environment;

        DialogeHistory*     history;
        MyGUI::ListPtr      topicsList;
    };
}
#endif
