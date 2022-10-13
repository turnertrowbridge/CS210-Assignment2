#include "promotedCarModelStack.h"

#include <utility>

/**
 * I the undersigned promise that the submitted assignment is my own work. While I was
 * free to discuss ideas with others, the work contained is my own. I recognize that
 * should this not be the case; I will be subject to penalties as outlined in the course
 * syllabus.
 * Name: Turner Trowbridge
 * Red ID: 827959204
 */

/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push(string model, int price) {
        //push latestModel onto stack
        PromotedModel latestModel = PromotedModel(model, price);
        latestPromotedModelStack.push_front(latestModel);

        //compare latestModel to saved highs and lows on highAndLowPromotedList and
        // push front if greater than saved high, push back if less than saved low
        if (maxMinStack.empty()){
            maxMinStack.push_front(make_pair(latestModel, latestModel));

            cout << "first price: $" << maxMinStack.front().first.getPromotedPrice() << "\nsecond price: $" << maxMinStack.front().second.getPromotedPrice() << endl;

        }else if (price >= maxMinStack.front().first.getPromotedPrice()) {
            maxMinStack.push_front(make_pair(latestModel, maxMinStack.front().second));
        } else if (price <= maxMinStack.front().second.getPromotedPrice()) {
            maxMinStack.push_front(make_pair(maxMinStack.front().first, latestModel));
        }
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    // save latestModel and pop
    PromotedModel latestModel = latestPromotedModelStack.front();
    latestPromotedModelStack.pop_front();
    maxMinStack.pop_front();

    return latestModel;
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //peek at the latestModel
    PromotedModel latestModel = latestPromotedModelStack.front();
    return latestModel;
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get highest priced model which is stored at front
    PromotedModel highestPricedModel = maxMinStack.front().first;
    cout << "Highest Priced Model: $" << highestPricedModel.getPromotedPrice() << endl;

    return highestPricedModel;
}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
    //throw exception if stack is empty
    if (latestPromotedModelStack.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }

    //get lowest priced model which is stored in second part of the front of the stack
    PromotedModel lowestPricedModel = maxMinStack.front().second;
    cout << "Lowest Priced Model: $" << lowestPricedModel.getPromotedPrice() << endl;

    return lowestPricedModel;
}