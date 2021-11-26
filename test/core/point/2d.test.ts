import { Point } from '../../../index'

describe('[core] Point 2D', () => {
  describe('constructors', () => {
    it('initializes from numbers', () => {
      const point = new Point(10, 20)

      expect(point.getX()).toStrictEqual(10)
      expect(point.getY()).toStrictEqual(20)
    })

    it('initializes from Point instance', () => {
      const point = new Point(new Point(20, 30))

      expect(point.getX()).toStrictEqual(20)
      expect(point.getY()).toStrictEqual(30)
    })
  })
})
