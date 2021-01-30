//
// Created by heersin on 1/30/21.
//

#ifndef SWARMRAY_COMMAND_H
#define SWARMRAY_COMMAND_H


class Command {
public:
    virtual void exec() = 0 ;
    virtual ~Command() = default;
};

class BuiltInCommand : public Command{
public:
    void exec() override;
};

class ExternCommand : public Command{
public:
    void exec() override;
};

#endif //SWARMRAY_COMMAND_H
