type action =
  | Increment(int)
  | Decrement(int)
  | Reset;

type state = {count: int};

let component = ReasonReact.reducerComponent("Counter");

let make = (_children) => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch action {
    | Increment(value) => ReasonReact.Update({count: state.count + value})
    | Decrement(value) => ReasonReact.Update({count: state.count - value})
    | Reset => ReasonReact.Update({count: 0})
    },
  render: (self) => {
    let count = string_of_int(self.state.count);
    <div className="Counter-container">
      <button onClick=(self.reduce((_event) => Increment(10)))>
        (ReasonReact.stringToElement("+"))
      </button>
      <div className="Counter-value"> (ReasonReact.stringToElement(count)) </div>
      <button onClick=(self.reduce((_event) => Decrement(10)))>
        (ReasonReact.stringToElement("-"))
      </button>
      <button onClick=(self.reduce((_event) => Reset))>
        (ReasonReact.stringToElement("Reset"))
      </button>
    </div>
  }
};